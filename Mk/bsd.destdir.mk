#-*- tab-width: 4; -*-
# ex:ts=4
#
# bsd.destdir.mk - Support for chrooted installation
#
#
# Please make sure all changes to this file are passed through the maintainer.

DESTDIR_Include_MAINTAINER=		portmgr@FreeBSD.org

#
# The target order is always: pre-chroot do-chroot post-chroot
#
# pre-chroot
#			- You can use this for special preparation work, that
#			  want to do before chrooting into the destination
#			  environment and doing the real build.  At default
#			  this target is empty.
#
# do-chroot
#			- This is the main target for doing the chrooted
#			  operations.  It mounts the ports tree and devfs into
#			  the destination environment and starts make(1)
#			  by calling chroot(1).
#
# post-chroot
#			- This target runs chrooted just after chroot(1) was
#			  called.  You can use this for special preparation
#			  work for the chrooted build if necessary.  At
#			  default, this target is empty.
#
# DESTDIR_ENV_LIST
#			- Contains names of the variables in host environ(7),
#			  which should be imported into the chrooted environ
#			  along with their values.
#			  Default: empty.
#
# DESTDIR_MOUNT_LIST
#			- Contains the directories to mount into the
#			  destination.  This is to make PORTSDIR, DISTDIR, etc.
#			  available in the destination environment.  Three
#			  forms of entries are allowed:
#			  VAR
#				- Mounts the path contained by VAR into
#				  a temporary directory and sets VAR to that
#				  directory in the destination environ(7).
#			  VAR:HOST_PATH
#				- Mounts HOST_PATH to a a temporary directory
#				  and sets VAR to that directory in the
#				  destination environ(7).
#			  VAR:HOST_PATH:DEST_PATH
#				- Mounts HOST_PATH to DEST_PATH and sets VAR
#				  to DEST_PATH in the destination environ(7).
#			  Default: PORTSDIR DISTDIR
#
# You can use something like this in host /etc/make.conf to
# customize per-chroot environment:
#	.if ${DESTDIR}=/foo/bar
#	PREFIX=/opt
#	CFLAGS=-O3 -pipe
#	DESTDIR_ENV_LIST=PREFIX CFLAGS
#	.endif
#

.if !defined(_DESTDIRMKINCLUDED)

_DESTDIRMKINCLUDED=	yes

.  if defined(WITH_DESTDIR_DEBUG)
DEBUG_MSG=	${ECHO_MSG} "DEBUG:"
.  else
DEBUG_MSG=	${TRUE}
.  endif

DESTDIR_ENV_LIST?=
DESTDIR_ENV=	CHROOTED=yes PATH=${PATH} TERM=${TERM}
.  for _var in ${DESTDIR_ENV_LIST:NDESTDIR:NCHROOTED:NPORTSDIR}
DESTDIR_ENV+=	${_var}="${${_var}}"
.  endfor

# Processing DESTDIR_MOUNT_LIST into something more machine-readable
# VAR:HOST_PATH:DEST_PATH
# VAR -> VAR:${VAR}:TMP
# VAR:HOST_PATH -> VAR:HOST_PATH:TMP
DESTDIR_MOUNT_LIST?=	PORTSDIR DISTDIR
_DESTDIR_MOUNT_LIST=
.  for _entry in ${DESTDIR_MOUNT_LIST}
__entry=${_entry}
.    if ${__entry:M*\:*\:*}
_DESTDIR_MOUNT_LIST+=	${_entry}
.    elif ${__entry:M*\:*}
_DESTDIR_MOUNT_LIST+=	${_entry}:___temp___
.    else
.      if defined(${_entry}) && !empty(${_entry})
_DESTDIR_MOUNT_LIST+=	${_entry}:${${_entry}}:___temp___
.      endif
.    endif
.  endfor

.MAIN:	all
.  for _target in ${.TARGETS}
${_target}: pre-chroot do-chroot
	@${TRUE}
.  endfor

.  if !target(pre-chroot)
pre-chroot:
	@${TRUE}
.  endif

.  if !target(do-chroot)
do-chroot:
	@if [ ! -d ${DESTDIR} ]; then \
		${ECHO_MSG} "===>  Directory ${DESTDIR} does not exist"; \
		${ECHO_MSG} "===>  Please set DESTDIR to a valid jail environment."; \
		exit 1; \
	fi; \
	_destdir=`${REALPATH} ${DESTDIR}`; \
	_mounted_entries_list=""; \
	_created_mountpoints_list=""; \
	_var_path_list=""; \
	${ECHO_MSG} "===>  Creating some important subdirectories"; \
	for _dir in tmp dev; do \
		[ -d $${_destdir}/$${_dir} ] || \
			if ${MKDIR} $${_destdir}/$${_dir}; then \
				${ECHO_MSG} "===> /$${_dir} subdirectory has been successfully created"; \
				_created_mountpoints_list="$${_destdir}/$${_dir} $${_created_mountpoints_list}"; \
			else \
				${ECHO_MSG} "===> /$${_dir} subdirectory could not be created"; \
				exit 2; \
			fi; \
	done; \
	${DEBUG_MSG} "_DESTDIR_MOUNT_LIST=${_DESTDIR_MOUNT_LIST}"; \
	for _entry in ${_DESTDIR_MOUNT_LIST}; do \
		${DEBUG_MSG} "Processing $${_entry}"; \
		_mount_var=$${_entry%%:*}; \
		_tp=$${_entry#*:}; \
		_host_path=`${REALPATH} $${_tp%:*}`; \
		_dest_path=$${_entry##*:}; \
		_full_dest_path=`${REALPATH} -q $${_destdir}/$${_dest_path} || :`; \
		_entry_was_created=0; \
		_entry_should_mount=0; \
		${DEBUG_MSG} "$${_mount_var}:$${_host_path}:$${_full_dest_path}"; \
		if [ "$${_dest_path}" = "___temp___" ]; then \
			${DEBUG_MSG} "Creating temporary mount point"; \
			if _full_dest_path=`${MKTEMP} -d $${_destdir}/tmp/mountpoint.XXXXXX`; then \
				${DEBUG_MSG} "Temporary mount point $${_full_dest_path} created successfully"; \
				_entry_was_created=1; \
				_entry_should_mount=1; \
				_dest_path=$${_full_dest_path#$${_destdir}}; \
				_created_mountpoints_list="$${_full_dest_path} $${_created_mountpoints_list}"; \
			else \
				${ECHO_MSG} "===> Failed to create temporary mount point"; \
				exit 9; \
			fi; \
		else \
			${DEBUG_MSG} "Checking if already mounted"; \
			if ${MOUNT}|${GREP} -qs "^$${_host_path} on $${_full_dest_path} ("; then \
				${DEBUG_MSG} "$${_host_path} is already mounted on $${_full_dest_path}"; \
				_var_path_list="$${_var_path_list} $${_mount_var}=$${_dest_path}"; \
			else \
				${DEBUG_MSG} "$${_host_path} is not mounted on $${_full_dest_path}"; \
				_entry_should_mount=1; \
			fi; \
		fi; \
		[ -d $${_full_dest_path} ] || \
			if ${MKDIR} $${_full_dest_path}; then \
				${DEBUG_MSG} "Mount point $${_full_dest_path} created"; \
				_entry_was_created=1; \
				_created_mountpoints_list="$${_created_mountpoints_list} ${_full_dest_path}"; \
			else \
				${ECHO_MSG} "===> Mount point $${_full_dest_path} could not be created"; \
				exit 7; \
			fi; \
		[ "$${_entry_should_mount}" = "0" ] || \
			if ${MOUNT_NULLFS} $${_host_path} $${_full_dest_path}; then \
				${DEBUG_MSG} "Directory $${_host_path} mounted"; \
				_mounted_entries_list="$${_full_dest_path} $${_mounted_entries_list}"; \
				_var_path_list="$${_var_path_list} $${_mount_var}=$${_dest_path}"; \
			else \
				${ECHO_MSG} "===> Dir $${_host_path} could not be mounted"; \
				[ "$${_entry_was_created}" = "0" ] || \
					${RMDIR} $${_full_dest_path} || ${TRUE}; \
				exit 8; \
			fi; \
	done; \
	${DEBUG_MSG} "Handling devfs separately"; \
	_full_dest_path=$${_destdir}/dev; \
	${MOUNT}|${GREP} -qs "^devfs on $${_full_dest_path} (" || \
		if ${MOUNT_DEVFS} $${_full_dest_path}; then \
			${DEBUG_MSG} "devfs mounted"; \
			_mounted_entries_list="$${_full_dest_path} $${_mounted_entries_list}"; \
		else \
			${ECHO_MSG} "===> devfs could not be mounted"; \
			[ -n "$${_created_mountpoints_list%%* $${_destdir}/dev *}" ] || \
				${RMDIR} $${_destdir}/dev || ${TRUE}; \
			exit 9; \
		fi; \
	_var_path_list="$${_var_path_list} DEVFS=/dev"; \
	${DEBUG_MSG} "Things we mounted: $${_mounted_entries_list}"; \
	${DEBUG_MSG} "Things we created: $${_created_mountpoints_list}"; \
	${DEBUG_MSG} "_var_path_list: $${_var_path_list}"; \
	${ECHO_MSG} "===>  Starting chrooted make in ${DESTDIR}..."; \
	export $${_var_path_list}; \
	${CHROOT} $${_destdir} ${SH} -c "\
		cd $${PORTSDIR}${.CURDIR:S|^${PORTSDIR}||}; \
		${SETENV} -i ${DESTDIR_ENV} $${_var_path_list} ${MAKE} ${.TARGETS}" && \
		{ status=$$?; ${ECHO_MSG} "===>  Chrooted make in ${DESTDIR} succeeded"; } || \
		{ status=$$?; ${ECHO_MSG} "===>  Chrooted make in ${DESTDIR} failed"; }; \
		${ECHO_MSG} "===>  Cleaning up..."; \
	for _entry in $${_mounted_entries_list}; do \
		${UMOUNT} -f $${_entry} || ${TRUE}; \
	done; \
	for _entry in $${_created_mountpoints_list}; do \
		${RMDIR} $${_entry} || ${TRUE}; \
	done; \
	exit $$status
.  endif	# !target(do-chroot)
.endif	# !defined(_DESTDIRMKINCLUDED)

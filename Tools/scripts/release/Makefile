# $FreeBSD$
#
# The purpose of this Makefile is to setup a standardized environment
# for making package splits.  Basically, for each split the organization
# looks like this:
#
#	src/release/scripts
#	ports/Tools/scripts/release
#		RELEASE (e.g. 4.6-RELEASE or 4.6-RC1)
#			symlinks to scripts required
#			directories used by scripts
#			config files
#
# The desire is to provide the scripts with the environment they
# expect while preserving the ability to cvs update them.

RELEASE?=
SRCSCRIPTDIR?=	/usr/src/release/scripts
SRCSCRIPTS=	print-cdrom-packages.sh
PORTSCRIPTS!=	echo *.pl *.sh
FORCE?=		no
PWD!=		pwd

all:
	@if [ -z "${RELEASE}" ]; then \
		echo "Release must be specified, i.e.:"; \
		echo "	make RELEASE=4.6-RELEASE"; \
		exit 1; \
	fi
	@if [ -d "${RELEASE}" -a "${FORCE}" = "no" ]; then \
		echo "The release directory ${RELEASE} already exists."; \
		echo "To force setup type:"; \
		echo "	make RELEASE=${RELEASE} FORCE=yes"; \
		exit 1; \
	fi
	# We *could* use mkdir -p, but being explicit helps.
	mkdir ${RELEASE}
.for SUBDIR in disc1 disc3 gen
	mkdir ${RELEASE}/${SUBDIR}
.endfor
.for SCRIPT in ${PORTSCRIPTS}
	cd ${RELEASE} && ln -s ../${SCRIPT} .
.endfor
.for SRCSCRIPT in ${SRCSCRIPTS}
	cd ${RELEASE} && ln -s ${SRCSCRIPTDIR}/${SRCSCRIPT} .
	@echo "Done."
.endfor
	cd ${RELEASE} && ln -s ../config .

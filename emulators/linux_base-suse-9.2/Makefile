# New ports collection makefile for:    linux_base
# Version required:     6.1
# Date created:         Jul 7, 1999
# Whom:                 marcel@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=		linux_base
PKGNAME=		linux_base-6.1
CATEGORIES=		emulators
MASTER_SITES=		${RPM_MIRRORS:S/__DIR__/${STDDIR}/g}
DISTFILES=		${RPM_SET1} ${RPM_LDCONFIG} ${RPM_SET2} \
			${RPM_RPM} ${RPM_SET3}

PATCH_SITES=		${RPM_MIRRORS:S/__DIR__/${UPDDIR}/g}
PATCHFILES=		${UPDATES}

MAINTAINER=		marcel@FreeBSD.org

RUN_DEPENDS=		rpm:${PORTSDIR}/misc/rpm

ONLY_FOR_ARCHS=		alpha i386
DIST_SUBDIR=		rpm
PREFIX=			/usr/compat/linux
EXTRACT_ONLY=
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
PLIST=			${PKGDIR}/PLIST.${MACHINE_ARCH}

RPM_MIRRORS=		\
	ftp://ftp.cdrom.com/pub/linux/redhat/__DIR__/ \
	ftp://ftp.redhat.com/redhat/__DIR__/ \
	ftp://ftp.infomagic.com/pub/mirrors/linux/RedHat/__DIR__/ \
	ftp://ftp.crc.ca/mirrors/by-site/ftp.redhat.com/redhat/__DIR__/ \
	ftp://ftp.nluug.nl/site/ftp.redhat.com/redhat/__DIR__/ \
	ftp://mirror.nucba.ac.jp/mirror/redhat/__DIR__/ \
	ftp://ftp.is.co.za/linux/distributions/redhat/__DIR__/ \
	ftp://mirror.aarnet.edu.au/pub/linux/redhat/__DIR__/

STDDIR=			redhat-6.1/${MACHINE_ARCH}/RedHat/RPMS
UPDDIR=			updates/6.1/${MACHINE_ARCH}

.include <bsd.port.pre.mk>

.if (${MACHINE_ARCH} == "i386")
LIBC5_COMPAT=		ld.so-1.9.5-11.i386.rpm libc-5.3.12-31.i386.rpm
RPM_BINUTILS=		binutils-2.9.1.0.23-6.i386.rpm
RPM_GLIB=		glib-1.2.5-1.i386.rpm
RPM_GLIBC=		glibc-2.1.2-11.i386.rpm
RPM_LDCONFIG=		ldconfig-1.9.5-15.i386.rpm
RPM_RPM=		rpm-3.0.3-2.i386.rpm
RPM_X_LIBS=		XFree86-libs-3.3.5-3.i386.rpm
UPDATES=		glib-1.2.6-2.i386.rpm
.else
LIBC5_COMPAT=
RPM_BINUTILS=		binutils-2.9.1.0.23-7.alpha.rpm
RPM_GLIB=		glib-1.2.6-2.alpha.rpm
RPM_GLIBC=		glibc-2.1.2-17.alpha.rpm
RPM_LDCONFIG=		ldconfig-1.9.5-16.alpha.rpm
RPM_RPM=		rpm-3.0.3-6.alpha.rpm
RPM_X_LIBS=		XFree86-libs-3.3.5-17.alpha.rpm
UPDATES=
.endif

#
# The file files/pkg-list lists all rpms that are installed by this port
# versus all rpms installed by a minimal Redhat installation.
#
RPM_SET1=		setup-2.0.5-1.noarch.rpm \
			filesystem-1.3.5-1.noarch.rpm \
			basesystem-6.0-4.noarch.rpm
RPM_SET2=		${RPM_GLIBC} \
			termcap-9.12.6-15.${MACHINE_ARCH}.rpm \
			libtermcap-2.0.8-18.${MACHINE_ARCH}.rpm \
			bash-1.14.7-16.${MACHINE_ARCH}.rpm \
			ncurses-4.2-25.${MACHINE_ARCH}.rpm \
			zlib-1.1.3-5.${MACHINE_ARCH}.rpm \
			info-3.12h-2.${MACHINE_ARCH}.rpm \
			fileutils-4.0-8.${MACHINE_ARCH}.rpm \
			grep-2.3-2.${MACHINE_ARCH}.rpm \
			${RPM_BINUTILS} \
			gd-1.3-5.${MACHINE_ARCH}.rpm \
			gdbm-1.8.0-2.${MACHINE_ARCH}.rpm \
			${RPM_GLIB} \
			${LIBC5_COMPAT} \
			libstdc++-2.9.0-24.${MACHINE_ARCH}.rpm \
			sh-utils-2.0-1.${MACHINE_ARCH}.rpm \
			readline-2.2.1-5.${MACHINE_ARCH}.rpm \
			redhat-release-6.1-1.noarch.rpm
RPM_SET3=		setserial-2.15-2.${MACHINE_ARCH}.rpm \
			slang-1.2.2-4.${MACHINE_ARCH}.rpm \
			stat-1.5-11.${MACHINE_ARCH}.rpm \
			tcsh-6.08.00-6.${MACHINE_ARCH}.rpm \
			${RPM_X_LIBS} \
			xpm-3.4k-1.${MACHINE_ARCH}.rpm

DBPATH=			/var/lib/rpm
RPMFLAGS=		--ignoreos --root ${PREFIX} --dbpath ${DBPATH} \
			--nodeps --replacepkgs
RPMDIR=			${DISTDIR}/${DIST_SUBDIR}

REMOVE_DIRS=		/dev /home /root /tmp /var/tmp /usr/local /usr/tmp
REMOVE_FILES=		/bin/df /bin/su /etc/exports /etc/group \
			/etc/localtime /etc/motd /etc/passwd /etc/printcap \
			/etc/services /etc/protocols

.if ${OSVERSION} <= 320001
#
# Hack to let the rpm installer run.  The actual kernel change occurred after
# 400008 on 4.0-current and well after 320001, but we'll assume people running
# -current and -stable stay reasonably up-to-date.
#
# Define this if you get messages that look like
#
# --
# ELF interpreter /compat/linux/lib/ld-linux.so.2 not found
# execution of script failed
# --
#
NEEDLOADLINK=		true
.endif

do-patch:
	@${DO_NADA}

do-install:
	@if [ -z "`kldstat -v | ${GREP} -E 'linux(aout|elf)'`" ]; then \
		${ECHO} 'Linux mode is not enabled.\
			Loading linux kernel module...' | fmt; \
		linux || { \
		${ECHO} 'The linux kernel module could not be loaded.\
			Please manually load the module and retry.\
			See "man linux" for details.' | fmt; \
		${FALSE}; \
		};\
	fi
	@${MKDIR} ${PREFIX}/${DBPATH}
	@${MKDIR} ${PREFIX}/var/tmp
	@rpm --initdb --root ${PREFIX} --dbpath ${DBPATH}
#
# Make sure we have a /dev/null in the chrooted environment.
#
	@${MKDIR} ${PREFIX}/dev
	@${RM} -f ${PREFIX}/dev/null
	@mknod ${PREFIX}/dev/null c 2 2
	@${CHMOD} 666 ${PREFIX}/dev/null
.if defined(NEEDLOADLINK)
	@${MKDIR} ${PREFIX}/compat
	@${LN} -s / ${PREFIX}/compat/linux
.endif
#
# Install all packages. Ignore dependencies just
# like the Red Hat installer.
#
	@for R in ${RPM_SET1}; do \
		${ECHO} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
	@${ECHO} ${RPM_LDCONFIG}
	@rpm -U ${RPMFLAGS} --noscripts ${RPMDIR}/${RPM_LDCONFIG}
	@brandelf -t Linux ${PREFIX}/sbin/ldconfig
	@${PREFIX}/sbin/ldconfig
	@${TOUCH} ${PREFIX}/etc/ld.so.conf
	@for R in ${RPM_SET2}; do \
		${ECHO} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
	@${ECHO} ${RPM_RPM}
	@rpm -U ${RPMFLAGS} --noscripts ${RPMDIR}/${RPM_RPM}
	@brandelf -t Linux ${PREFIX}/bin/rpm
	@for R in ${RPM_SET3}; do \
		${ECHO} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
#
# Install updates
#
	@for R in ${PATCHFILES}; do \
		${ECHO} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
#
# Install yp.conf as a hint to NIS users
#
	${INSTALL} ${COPY} -m 644 ${FILESDIR}/yp.conf ${PREFIX}/etc
#
# Finish
#
.if defined(NEEDLOADLINK)
	@${RM} -rf ${PREFIX}/compat
.endif
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${PREFIX}/$$D; \
	done
	@for F in ${REMOVE_FILES}; do \
		${RM} ${PREFIX}/$$F; \
	done
	@${LN} -s /var/tmp ${PREFIX}/usr/tmp

post-install:
	@${ECHO} ''
	@fmt ${PKGMESSAGE}
	@${ECHO} ''

.include <bsd.port.post.mk>

# New ports collection makefile for:	zh-cle_base
# Date created:		Nov 17, 1999
# Whom:			keith@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		cle_base
PORTVERSION=		0.9p1
PORTREVISION=	1
CATEGORIES=		chinese emulators linux
MASTER_SITES=		\
	ftp://cle.linux.org.tw/pub/CLE/stable/v0.9p1/i386/RedHat/RPMS/ \
	ftp://freebsd.sinica.edu.tw/pub/keith/zh-rpm/
DISTFILES=		${RPM_SET1} ${RPM_LDCONFIG} ${RPM_BASH2} ${RPM_SET2} \
			${RPM_RPM} ${RPM_SET3} ${RPM_L10N}
EXTRACT_ONLY=

MAINTAINER=		ports@FreeBSD.org
COMMENT=		The base set of CLE packages needed in Linux mode, support both GB & Big5

RUN_DEPENDS=		rpm:${PORTSDIR}/archivers/rpm

CONFLICTS=		linux_base-*
ONLY_FOR_ARCHS=		i386
DIST_SUBDIR=		zh-rpm
PREFIX=			${LINUXBASE}
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
PKGINSTALL=		${WRKDIR}/pkg-install

.include <bsd.port.pre.mk>

LIBC5_COMPAT=		ld.so-1.9.5-13.i386.rpm libc-5.3.12-31.i386.rpm
RPM_BINUTILS=		binutils-2.9.5.0.22-6.i386.rpm
RPM_GLIB=		glib-1.2.6-3.i386.rpm
RPM_GLIBC=		glibc-2.1.3-21.i386.rpm
RPM_LDCONFIG=		ldconfig-1.9.5-16.i386.rpm
RPM_RPM=		rpm-3.0.5-9.6x.i386.rpm
RPM_X_LIBS=		XFree86-libs-3.3.6-24CLE.i386.rpm

#
# The file files/base-list lists all rpms that are installed
# by a minimal RedHat installation versus all rpms installed
# by this port.
#
RPM_SET1=		setup-2.1.8-1.noarch.rpm \
			filesystem-1.3.5-1.noarch.rpm \
			basesystem-6.0-4.noarch.rpm
RPM_SET2=		${RPM_GLIBC} \
			termcap-10.2.7-9.noarch.rpm \
			libtermcap-2.0.8-20.i386.rpm \
			bash-2.04-1.i386.rpm \
			ncurses-5.0-11.i386.rpm \
			zlib-1.1.3-6.i386.rpm \
			info-4.0-5.i386.rpm \
			fileutils-4.0-21.i386.rpm \
			grep-2.4-3.i386.rpm \
			${RPM_BINUTILS} \
			gd-1.3-6.i386.rpm \
			gdbm-1.8.0-3.i386.rpm \
			${RPM_GLIB} \
			${LIBC5_COMPAT} \
			libstdc++-2.9.0-30.i386.rpm \
			sh-utils-2.0-5.i386.rpm \
			readline-2.2.1-6.i386.rpm \
			cle-release-0.9p1-2.noarch.rpm
RPM_SET3=		setserial-2.15-3.i386.rpm \
			slang-1.2.2-5.i386.rpm \
			stat-1.5-12.i386.rpm \
			tcsh-6.09-4.i386.rpm \
			xpm-3.4k-2.i386.rpm
RPM_L10N=		${RPM_X_LIBS} \
			locale-zh-0.9-3.i386.rpm \
			xa+cv-0.7-pre1.i386.rpm

DBPATH=			/var/lib/rpm
RPMFLAGS=		--ignoreos --root ${LINUXBASE} --dbpath ${DBPATH} \
			--nodeps --replacepkgs --notriggers --noscripts
RPMDIR=			${DISTDIR}/${DIST_SUBDIR}

REMOVE_DIRS=		/dev /home /root /tmp /var/tmp /usr/local /usr/tmp
REMOVE_FILES=		/bin/df /bin/su /etc/exports /etc/group \
			/etc/localtime /etc/motd /etc/passwd /etc/printcap \
			/etc/services /etc/protocols

.if ${OSVERSION} >= 500113
BROKEN=         "Does not install (attempts to overwrite something in /proc)"
.endif

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

post-patch:
	@${SED} -e "s;@LINUXBASE@;${LINUXBASE};g" ${FILESDIR}/INSTALL.in > ${WRKDIR}/pkg-install

pre-install:
# Handle the loading of the linux loadable kernel module if
# required.
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${LINUXBASE}/${DBPATH}
	@${MKDIR} ${LINUXBASE}/var/tmp
	@rpm --initdb --root ${LINUXBASE} --dbpath ${DBPATH}
#
# Make sure we have a /dev/null in the chrooted environment.
#
	@${MKDIR} ${LINUXBASE}/dev
	@${RM} -f ${LINUXBASE}/dev/null
	@mknod ${LINUXBASE}/dev/null c 2 2
	@chmod 666 ${LINUXBASE}/dev/null
.if defined(NEEDLOADLINK)
	@${MKDIR} ${LINUXBASE}/compat
	@${LN} -s / ${LINUXBASE}/compat/linux
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
	@rpm -U ${RPMFLAGS} ${RPMDIR}/${RPM_LDCONFIG}
	@brandelf -t Linux ${LINUXBASE}/sbin/ldconfig
	@for R in ${RPM_SET2}; do \
		${ECHO} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
	@brandelf -t Linux ${LINUXBASE}/bin/sh
	@${ECHO} ${RPM_RPM}
	@rpm -U ${RPMFLAGS} ${RPMDIR}/${RPM_RPM}
	@brandelf -t Linux ${LINUXBASE}/bin/rpm
	@for R in ${RPM_SET3}; do \
		${ECHO} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
	@for R in ${RPM_L10N}; do \
		${ECHO} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
	@ln -sf ${LINUXBASE}/usr/X11R6/lib/libXpm.so.4.11 ${LINUXBASE}/usr/X11R6/lib/libXpm.so.4
	@echo "/usr/i486-linux-libc5/lib" > ${LINUXBASE}/etc/ld.so.conf
	@echo "/usr/X11R6/lib" >> ${LINUXBASE}/etc/ld.so.conf
	@${LINUXBASE}/sbin/ldconfig
#
# Install yp.conf as a hint to NIS users
#
	${INSTALL} ${COPY} -m 644 ${FILESDIR}/yp.conf ${LINUXBASE}/etc
#
# Finish
#
.if defined(NEEDLOADLINK)
	@${RM} -rf ${LINUXBASE}/compat
.endif
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${LINUXBASE}/$$D; \
	done
	@for F in ${REMOVE_FILES}; do \
		${RM} ${LINUXBASE}/$$F; \
	done
	@${LN} -s /var/tmp ${LINUXBASE}/usr/tmp
	@${TOUCH} ${LINUXBASE}/CLE-0.9p1

post-install:
	@${ECHO} ''
	@fmt ${PKGMESSAGE}
	@${ECHO} ''

.include <bsd.port.post.mk>

# New ports collection makefile for:	CLE_base
# Date created:		Nov 17, 1999
# Whom:			keith@freebsd.sinica.edu.tw
#
# $FreeBSD$
#

PORTNAME=		linux_base
PORTVERSION=		0.9p1
CATEGORIES=		chinese emulators linux
MASTER_SITES=		\
	ftp://cle.linux.org.tw/pub/CLE/i386/RedHat/RPMS/ \
	ftp://freebsd.sinica.edu.tw/pub/keith/zh-rpm/ \
	ftp://ftp.nsysu.edu.tw/Linux/CLE/RedHat/i386/RedHat/RPMS/ \
	ftp://freebsd.ntu.edu.tw/UNIX/Linux/CLE/RedHat/i386/RedHat/RPMS/ \
	ftp://ftp.knb.com.hk/pub/CLE/RedHat/0.9/RedHat/RPMS/
DISTFILES=		${RPM_SET1} ${RPM_LDCONFIG} ${RPM_BASH2} ${RPM_SET2} \
			${RPM_RPM} ${RPM_SET3} ${RPM_L10N}

MAINTAINER=		keith@freebsd.sinica.edu.tw

RUN_DEPENDS=		rpm:${PORTSDIR}/misc/rpm

ONLY_FOR_ARCHS=		i386
DIST_SUBDIR=		zh-rpm
#EXTRACT_ONLY=
PREFIX=			/compat/linux
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
PKGINSTALL=		${WRKDIR}/pkg-install

.include <bsd.port.pre.mk>

LIBC5_COMPAT=		ld.so-1.9.5-13.i386.rpm libc-5.3.12-31.i386.rpm
RPM_BINUTILS=           binutils-2.9.5.0.22-6.i386.rpm
RPM_GLIB=               glib-1.2.6-3.i386.rpm
RPM_GLIBC=              glibc-2.1.3-21.i386.rpm
RPM_LDCONFIG=           ldconfig-1.9.5-16.i386.rpm
RPM_RPM=                rpm-3.0.5-9.6x.i386.rpm
RPM_X_LIBS=             XFree86-libs-3.3.6-24CLE.i386.rpm

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
RPMFLAGS=		--ignoreos --root ${PREFIX} --dbpath ${DBPATH} \
			--nodeps --replacepkgs --notriggers --noscripts
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

post-patch:
	@${SED} -e "s;@PREFIX@;${PREFIX};g" ${FILESDIR}/INSTALL.in > ${WRKDIR}/pkg-install

pre-install:
# Handle the loading of the linux loadable kernel module if
# required.
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${PREFIX}/${DBPATH}
	@${MKDIR} ${PREFIX}/var/tmp
	@rpm --initdb --root ${PREFIX} --dbpath ${DBPATH}
#
# Make sure we have a /dev/null in the chrooted environment.
#
	@${MKDIR} ${PREFIX}/dev
	@${RM} -f ${PREFIX}/dev/null
	@mknod ${PREFIX}/dev/null c 2 2
	@chmod 666 ${PREFIX}/dev/null
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
	@rpm -U ${RPMFLAGS} ${RPMDIR}/${RPM_LDCONFIG}
	@brandelf -t Linux ${PREFIX}/sbin/ldconfig
	@for R in ${RPM_SET2}; do \
		${ECHO} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
	@brandelf -t Linux ${PREFIX}/bin/sh
	@${ECHO} ${RPM_RPM}
	@rpm -U ${RPMFLAGS} ${RPMDIR}/${RPM_RPM}
	@brandelf -t Linux ${PREFIX}/bin/rpm
	@for R in ${RPM_SET3}; do \
		${ECHO} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
	@for R in ${RPM_L10N}; do \
		${ECHO} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
	@ln -sf ${PREFIX}/usr/X11R6/lib/libXpm.so.4.11 ${PREFIX}/usr/X11R6/lib/libXpm.so.4
	@echo "/usr/i486-linux-libc5/lib" > ${PREFIX}/etc/ld.so.conf
	@echo "/usr/X11R6/lib" >> ${PREFIX}/etc/ld.so.conf
	@${PREFIX}/sbin/ldconfig
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
	@${TOUCH} ${PREFIX}/CLE-0.9-PRE2

post-install:
	@${ECHO} ''
	@fmt ${PKGMESSAGE}
	@${ECHO} ''

.include <bsd.port.post.mk>

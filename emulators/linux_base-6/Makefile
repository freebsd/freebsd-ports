# New ports collection makefile for:    linux_base
# Date created:         Jul 7, 1999
# Whom:                 marcel@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		linux_base
PORTVERSION=		6.1
PORTREVISION=		6
CATEGORIES=		emulators linux
MASTER_SITES=		${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	${PORTVERSION}/en/os/${MACHINE_ARCH}/RedHat/RPMS
DISTFILES=		${RPM_SET1} ${RPM_LDCONFIG} ${RPM_SET2} \
			${RPM_RPM} ${RPM_SET3}

PATCH_SITES=		${MASTER_SITE_REDHAT_LINUX}
PATCH_SITE_SUBDIR=	updates/6.2/en/os/${MACHINE_ARCH} \
				updates/6.1/en/os/${MACHINE_ARCH} \
				6.2/en/os/${MACHINE_ARCH}/RedHat/RPMS
PATCHFILES=		${UPDATES}

MAINTAINER=		ports@FreeBSD.org
COMMENT=	The base set of packages needed in Linux mode
.if (${MACHINE_ARCH} == "alpha")
FORBIDDEN=	"see <URL:http://rhn.redhat.com/errata/RHSA-2003-089.html> or\
 <URL:http://www.cert.org/advisories/CA-2003-10.html>"
.endif

BUILD_DEPENDS=		rpm:${PORTSDIR}/archivers/rpm

CONFLICTS=cle_base-* linux_base-7* linux_base-8* linux_base-deb* linux_base-gen*
ONLY_FOR_ARCHS=		alpha i386
DIST_SUBDIR=		rpm
PREFIX=			${LINUXBASE}
EXTRACT_ONLY=
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_LATEST_LINK=		yes
NO_MTREE=		yes
PLIST=			${PKGDIR}/pkg-plist.${MACHINE_ARCH}
MD5_FILE=		${MASTERDIR}/distinfo.${MACHINE_ARCH}

.include <bsd.port.pre.mk>

RPM_GLIBC=		glibc-2.1.3-29.${MACHINE_ARCH}.rpm
UPDATES=		${RPM_GLIBC} \
			zlib-1.1.3-25.6.${MACHINE_ARCH}.rpm \
			XFree86-libs-3.3.6-29.${MACHINE_ARCH}.rpm \
			gtk+-1.2.6-7.${MACHINE_ARCH}.rpm
.if (${MACHINE_ARCH} == "i386")
LIBC5_COMPAT=		ld.so-1.9.5-11.i386.rpm libc-5.3.12-31.i386.rpm
RPM_BINUTILS=		binutils-2.9.1.0.23-6.i386.rpm
RPM_GLIB=
RPM_LDCONFIG=		ldconfig-1.9.5-15.i386.rpm
RPM_RPM=		rpm-3.0.3-2.i386.rpm
UPDATES+=		glib-1.2.6-2.i386.rpm
.else
LIBC5_COMPAT=
RPM_BINUTILS=		binutils-2.9.1.0.23-7.alpha.rpm
RPM_GLIB=		glib-1.2.6-2.alpha.rpm
RPM_LDCONFIG=		ldconfig-1.9.5-16.alpha.rpm
RPM_RPM=		rpm-3.0.3-6.alpha.rpm
UPDATES+=
.endif

#
# The file files/pkg-list lists all rpms that are installed by this port
# versus all rpms installed by a minimal Redhat installation.
#
RPM_SET1=		setup-2.0.5-1.noarch.rpm \
			filesystem-1.3.5-1.noarch.rpm \
			basesystem-6.0-4.noarch.rpm
RPM_SET2=		termcap-9.12.6-15.${MACHINE_ARCH}.rpm \
			libtermcap-2.0.8-18.${MACHINE_ARCH}.rpm \
			bash-1.14.7-16.${MACHINE_ARCH}.rpm \
			ncurses-4.2-25.${MACHINE_ARCH}.rpm \
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
			xpm-3.4k-1.${MACHINE_ARCH}.rpm

DBPATH=			/var/lib/rpm
RPM=			LC_ALL=C rpm
RPMFLAGS=		--ignoreos --root ${LINUXBASE} --dbpath ${DBPATH} \
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

pre-install:
#
# Handle the loading of the linux loadable kernel module if
# required.
#
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${LINUXBASE}/${DBPATH}
	@${MKDIR} ${LINUXBASE}/var/tmp
	@${RPM} --initdb --root ${LINUXBASE} --dbpath ${DBPATH}
#
# Make sure we have a /dev/null in the chrooted environment.
#
	@${MKDIR} ${LINUXBASE}/dev
	@${RM} -f ${LINUXBASE}/dev/null
	@mknod ${LINUXBASE}/dev/null c 2 2
	@${CHMOD} 666 ${LINUXBASE}/dev/null
.if defined(NEEDLOADLINK)
	@${MKDIR} ${LINUXBASE}/compat
	@${LN} -s / ${LINUXBASE}/compat/linux
.endif
#
# Install all packages. Ignore dependencies just
# like the Red Hat installer.
#
	@for R in ${RPM_SET1}; do \
		${ECHO_MSG} $$R; \
		${RPM} -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
	@${ECHO_MSG} ${RPM_LDCONFIG}
	@${RPM} -U ${RPMFLAGS} --noscripts ${RPMDIR}/${RPM_LDCONFIG}
	@brandelf -t Linux ${LINUXBASE}/sbin/ldconfig
	@${LINUXBASE}/sbin/ldconfig
	@${TOUCH} ${LINUXBASE}/etc/ld.so.conf
	@for R in ${RPM_GLIBC} \
		zlib-1.1.3-25.6.${MACHINE_ARCH}.rpm \
		${RPM_SET2} \
		XFree86-libs-3.3.6-29.${MACHINE_ARCH}.rpm; do \
			${ECHO_MSG} $$R; \
			${RPM} -U ${RPMFLAGS} ${RPMDIR}/$$R; \
		done
	@${ECHO_MSG} ${RPM_RPM}
	@${RPM} -U ${RPMFLAGS} --noscripts ${RPMDIR}/${RPM_RPM}
	@brandelf -t Linux ${LINUXBASE}/bin/rpm
	@for R in ${RPM_SET3}; do \
		${ECHO_MSG} $$R; \
		${RPM} -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
#
# Install updates
#
	@for R in ${PATCHFILES}; do \
		${ECHO_MSG} $$R; \
		${RPM} -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
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

post-install:
# Fix unknown uid/gids that come out of the RPMs, to avoid
# the quotacheck warning about unknown owners.
	@${CHOWN} root:wheel ${LINUXBASE}/usr/man/man8/setserial.8
	@${CHGRP} mail ${LINUXBASE}/var/spool/mail
	@${ECHO_MSG} ''
	@fmt ${PKGMESSAGE}
	@${ECHO_MSG} ''

.include <bsd.port.post.mk>

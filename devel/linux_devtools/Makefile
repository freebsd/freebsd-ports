# New ports collection makefile for:    linux_devtools
# Version required:     5.2
# Date created:         Jul 9, 1999
# Whom:                 marcel@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=		linux_devtools
PKGNAME=		linux_devtools-5.2
CATEGORIES=		emulators devel
MASTER_SITES=		\
	ftp://ftp.cdrom.com/pub/linux/redhat/${STDDIR}/ \
	ftp://ftp.redhat.com/redhat/${STDDIR}/ \
	ftp://ftp.infomagic.com/pub/mirrors/linux/RedHat/${STDDIR}/ \
	ftp://ftp.crc.ca/mirrors/by-site/ftp.redhat.com/redhat/${STDDIR}/ \
	ftp://ftp.nluug.nl/site/ftp.redhat.com/redhat/${STDDIR}/ \
	ftp://mirror.nucba.ac.jp/mirror/redhat/${STDDIR}/ \
	ftp://ftp.is.co.za/linux/distributions/redhat/${STDDIR}/ \
	ftp://mirror.aarnet.edu.au/pub/linux/redhat/$STDDIR}/
DISTFILES=		${KERN_HEADERS} \
			glibc-devel-2.0.7-29.${ARCH}.rpm \
			libstdc++-devel-2.8.0-14.${ARCH}.rpm \
			make-3.76.1-5.${ARCH}.rpm \
			egcs-1.0.3a-14.${ARCH}.rpm \
			egcs-c++-1.0.3a-14.${ARCH}.rpm \
			egcs-g77-1.0.3a-14.${ARCH}.rpm \
			gdb-4.17.0.4-3.${ARCH}.rpm \
			XFree86-devel-3.3.2.3-25.${ARCH}.rpm

MAINTAINER=		marcel@FreeBSD.org

RUN_DEPENDS=		\
	${PREFIX}/etc/redhat-release:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=		i386 alpha
DIST_SUBDIR=		rpm
PREFIX=			/compat/linux
EXTRACT_ONLY=
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
PLIST=			${PKGDIR}/PLIST.${ARCH}

STDDIR=			old-releases/redhat-5.2/${ARCH}/RedHat/RPMS

.include <bsd.port.pre.mk>

.if (${ARCH} == "i386")
KERN_HEADERS=		kernel-headers-2.0.36-0.7.i386.rpm
.else
KERN_HEADERS=		kernel-headers-2.0.35-5.alpha.rpm
.endif

DBPATH=			/var/lib/rpm
RPMFLAGS=		--ignoreos --root ${PREFIX} --dbpath ${DBPATH}
RPMDIR=			${DISTDIR}/${DIST_SUBDIR}

REMOVE_DIRS=		/dev /tmp /var/tmp
REMOVE_FILES=		/usr/X11R6/include/X11/X11

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
#
# Setup a chroot'able environment
#
	@${MKDIR} ${PREFIX}/tmp
	@${MKDIR} ${PREFIX}/var/tmp
	@${MKDIR} ${PREFIX}/dev
	@${RM} -f ${PREFIX}/dev/null
	@mknod ${PREFIX}/dev/null c 2 2
	@${CHMOD} 666 ${PREFIX}/dev/null
.if defined(NEEDLOADLINK)
	@${MKDIR} ${PREFIX}/compat
	@${RM} -f ${PREFIX}/compat/linux
	@${LN} -s / ${PREFIX}/compat/linux
.endif
#
# Install all packages.
#
	@for R in ${DISTFILES}; do \
		${ECHO} $$R; \
		rpm -i ${RPMFLAGS} --replacepkgs ${RPMDIR}/$$R || \
			${TRUE}; \
	done
#
# Finish
#
	@(cd ${PREFIX}/usr/bin; ${LN} -s egcs cc)
	@(cd ${PREFIX}/usr/bin; ${LN} -s egcs gcc)
.if defined(NEEDLOADLINK)
	@${RM} -rf ${PREFIX}/compat
.endif
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${PREFIX}/$$D; \
	done
	@for F in ${REMOVE_FILES}; do \
		${RM} ${PREFIX}/$$F; \
	done

.include <bsd.port.post.mk>

# New ports collection makefile for:	Mesa3 for Linux compat
# Date created:		May 18 2000
# Whom:			Masahiro TAKEMURA
#
# $FreeBSD$
#

PORTNAME=		mesa
PORTVERSION=		3.2.2
CATEGORIES=		graphics linux
MASTER_SITES=		${RPM_MIRRORS:S/__DIR__/${STDDIR}/g}
PKGNAMEPREFIX=		linux_
DISTFILES=		Mesa-${PORTVERSION:S/./-/g:S/-/./}.${MACHINE_ARCH}.rpm
EXTRACT_ONLY=

PATCH_SITES=		${RPM_MIRRORS:S/__DIR__/${UPDDIR}/g}
PATCHFILES=

MAINTAINER=		mastake@msel.t.u-tokyo.ac.jp

BUILD_DEPENDS=		rpm2cpio:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=		\
	/compat/linux/lib/ld-linux.so.2:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=		i386
DIST_SUBDIR=		rpm
PREFIX=			/compat/linux
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes

RPM_MIRRORS=		\
	ftp://ftp.freesoftware.com/pub/linux/redhat/__DIR__/ \
	ftp://ftp.redhat.com/redhat/__DIR__/ \
	ftp://ftp.infomagic.com/pub/mirrors/linux/RedHat/__DIR__/ \
	ftp://ftp.crc.ca/mirrors/by-site/ftp.redhat.com/redhat/__DIR__/ \
	ftp://ftp.nluug.nl/site/ftp.redhat.com/redhat/__DIR__/ \
	ftp://mirror.nucba.ac.jp/mirror/redhat/__DIR__/ \
	ftp://ftp.is.co.za/linux/distributions/redhat/__DIR__/ \
	ftp://mirror.aarnet.edu.au/pub/linux/redhat/__DIR__/

STDDIR=			redhat-6.2/${MACHINE_ARCH}/RedHat/RPMS
UPDDIR=			updates/6.2/${MACHINE_ARCH}

.include <bsd.port.pre.mk>

RPMDIR=			${DISTDIR}/${DIST_SUBDIR}

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
# Install all packages.
#
	@for R in ${DISTFILES}; do \
		${ECHO} $$R; \
		cd ${PREFIX} && rpm2cpio ${RPMDIR}/$$R | cpio -di; \
	done
#
# Install updates
#
	@for R in ${PATCHFILES}; do \
		${ECHO} $$R; \
		cd ${PREFIX} && rpm2cpio ${RPMDIR}/$$R | cpio -di; \
	done
#
# Create Symbolic link
#
	@for R in GL GLU; do \
		cd ${PREFIX}/usr/X11R6/lib && ${LN} -s lib$$R.so libMesa$$R.so; \
	done
#
# Finish
#
	${PREFIX}/sbin/ldconfig

.include <bsd.port.post.mk>

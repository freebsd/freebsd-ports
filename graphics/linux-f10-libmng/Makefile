# New ports collection makefile for: linux-libmng
# Date created:		01/09/18
# Whom:                 mranner@inode.at
#
# $FreeBSD$
#

PORTNAME=		libmng
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=		graphics linux
MASTER_SITES?=	${RPM_MIRRORS:S/__DIR__/${STDDIR}/g}
PKGNAMEPREFIX=	linux-
DISTNAME=		libmng-${PORTVERSION}-1.${MACHINE_ARCH}
EXTRACT_SUFX=	.rpm
EXTRACT_ONLY=

MAINTAINER=		mranner@inode.at
COMMENT=		RPM of libmng

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg

BASEVERSION=	8.0
USE_LINUX=	yes
USE_LINUX_PREFIX=	yes
ONLY_FOR_ARCHS=	i386

DIST_SUBDIR=	rpm
NO_BUILD=	yes
PLIST?=		${PKGDIR}/pkg-plist.${MACHINE_ARCH}
MD5_FILE?=	${MASTERDIR}/distinfo.${MACHINE_ARCH}

# Let's avoid hardcoding 'en' as the language.
LANG?=		en
RPM_MIRRORS=	\
	ftp://ftp.redhat.com/pub/redhat/__DIR__/ \
	ftp://ftp.nluug.nl/site/ftp.redhat.com/redhat/__DIR__/ \
	ftp://ftp.mirrorservice.org/sites/ftp.redhat.com/pub/redhat/__DIR__/
STDDIR=		linux/${BASEVERSION}/${LANG}/os/${MACHINE_ARCH}/RedHat/RPMS
UPDDIR=		linux/updates/${BASEVERSION}/${LANG}/os/${MACHINE_ARCH}
DBPATH=		/var/lib/rpm
RPMFLAGS=	--ignoreos --root ${PREFIX} --dbpath ${DBPATH} \
		--nodeps --replacepkgs
RPMDIR=		${DISTDIR}/${DIST_SUBDIR}

do-install:
	@for R in ${DISTFILES}; do \
		${ECHO_MSG} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R || true ; \
	done

.include <bsd.port.mk>

# New ports collection makefile for:	audio/linux-nas-libs
# Date created:				2009-09-01
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	nas
PORTVERSION=	1.8
CATEGORIES=	audio linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-libs
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Runtime libraries for NAS (Linux Fedora Core 4)

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
LINUX_DIST_VER=	4
RPMVERSION=	10.fc4
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libaudio.so.2 usr/lib/libaudio.so.2.4
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	BUGS FAQ HISTORY README TODO
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

REMOVE_DIRS=	etc usr/X11R6 usr/bin usr/share/man

# we need libraries only (Fedora 10 already has a separate RPM file
# for libraries)
pre-install:
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${WRKSRC}/$$D; \
	done

.include <bsd.port.mk>

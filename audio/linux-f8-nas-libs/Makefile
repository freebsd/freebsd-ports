# New ports collection makefile for:	audio/linux-f8-nas-libs
# Date created:				2009-09-01
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	nas
PORTVERSION=	1.9.1
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-f8-
PKGNAMESUFFIX=	-libs
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Runtime libraries for NAS (Linux Fedora 8)

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
LINUX_DIST_VER=	8
RPMVERSION=	2.fc8
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libaudio.so.2 usr/lib/libaudio.so.2.4
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	FAQ HISTORY README TODO
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

REMOVE_DIRS=	etc usr/bin usr/lib/X11 usr/share/man

# we need libraries only (Fedora 10 already has a separate RPM file
# for libraries)
pre-install:
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${WRKSRC}/$$D; \
	done

.include <bsd.port.mk>

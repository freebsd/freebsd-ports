# Ports collection makefile for:  klayout
# Date created:			  Sat, Apr 28, 2007
# Whom:				  Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	klayout
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	hrs

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A Qt-based GDS2 Viewer

USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network moc sql uic rcc qt3support xml
PLIST_FILES=	bin/klayout

PLATFORMKEYWORD=	freebsd-32-gcc-release

do-build:
	cd ${WRKSRC} \
		&& ${SH} build.sh -platform ${PLATFORMKEYWORD} -qt ${LOCALBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin.${PLATFORMKEYWORD}/klayout \
		${PREFIX}/bin

.include <bsd.port.mk>

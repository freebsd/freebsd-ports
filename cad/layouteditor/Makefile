# New ports collection makefile for:	layouteditor
# Date created:				Sun, Apr 29 2007
# Whom:					Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	layouteditor
PORTVERSION=	0.0.20101101
CATEGORIES=	cad
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	hrs
DISTNAME=	layout-${PORTVERSION:S,^0.0.,,}-gpl-src

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IC/MEMS layout editor

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network moc_build sql uic_build \
		rcc_build qmake qt3support xml
USE_ZIP=	yes
USE_FREETYPE=	yes
WRKSRC=		${WRKDIR}/layout
PLIST_FILES=	bin/layout

do-configure:
	cd ${WRKSRC} && ${QMAKE} -makefile -spec ${QMAKESPEC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/layout ${PREFIX}/bin/

.include <bsd.port.mk>

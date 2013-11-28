# Created by: Hiroki Sato <hrs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	layouteditor
PORTVERSION=	0.0.20110614
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	hrs
DISTNAME=	LayoutEditor-${PORTVERSION:S,^0.0.,,}-gpl-src

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IC/MEMS layout editor

LIB_DEPENDS=	libttf.so:${PORTSDIR}/print/freetype

USES=		qmake
USE_QT4=	corelib gui network moc_build sql uic_build \
		rcc_build qt3support xml
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/layout
PLIST_FILES=	bin/layout

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/layout ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>

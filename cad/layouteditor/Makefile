# Created by: Hiroki Sato <hrs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	layouteditor
PORTVERSION=	0.0.20110614
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	LOCAL/hrs
DISTNAME=	LayoutEditor-${PORTVERSION:S,^0.0.,,}-gpl-src

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IC/MEMS layout editor

LIB_DEPENDS=	libttf.so:print/freetype

BROKEN_armv6=		fails to compile: no matching member function for call to 'map'
BROKEN_armv7=		fails to compile: no matching member function for call to 'map'

USES=		qmake zip
USE_QT4=	corelib gui network moc_build sql uic_build \
		rcc_build qt3support xml
WRKSRC=		${WRKDIR}/layout
PLIST_FILES=	bin/layout

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/layout ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>

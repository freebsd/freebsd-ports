# $FreeBSD$

PORTNAME=	jamulus
DISTVERSIONPREFIX=	r
DISTVERSION=	3_7_0
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Internet jam session software

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjack.so:audio/jack

USES=		compiler:c++11-lang gl pkgconfig qmake qt:5
USE_QT=		concurrent core gui network widgets xml buildtools_build linguisttools_build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	jamulussoftware

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/jamulus.desktop \
		share/icons/hicolor/512x512/apps/jamulus.png

QMAKE_ARGS=	CONFIG+="noupcasename"

PORTSCOUT=	limit:^r\d+_ # prevent malformatted tags, like 'latest'

.include <bsd.port.mk>

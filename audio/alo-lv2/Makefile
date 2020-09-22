# $FreeBSD$

PORTNAME=	alo
DISTVERSION=	0.7-17
DISTVERSIONSUFFIX=	-g61e8b02
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Looper LV2 plugin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		compiler:c++11-lang gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	devcurmudgeon

WRKSRC_SUBDIR=	source

.include <bsd.port.mk>

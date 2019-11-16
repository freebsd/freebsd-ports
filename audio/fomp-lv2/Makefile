# $FreeBSD$

PORTNAME=	fomp
DISTVERSION=	1.2.0
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 port of the MCP, VCO, FIL, and WAH plugins by Fons Adriaensen

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		pkgconfig tar:bz2 waf

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/fomp.lv2/*.so

.include <bsd.port.mk>

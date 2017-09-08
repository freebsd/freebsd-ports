# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	mda-lv2
PORTVERSION=	1.2.2
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	yuri@rawbw.com
COMMENT=	LV2 port of the MDA plugins by Paul Kellett

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		waf pkgconfig tar:bz2

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/mda.lv2/*.so

.include <bsd.port.mk>

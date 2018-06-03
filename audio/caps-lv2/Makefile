# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	caps-lv2
PORTVERSION=	g20170626
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 version of the C* Audio Plugin Suite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		fails to build: dsp/v4f.h:153:12: no matching function for call to v4f_map
BROKEN_armv7=		fails to build: dsp/v4f.h:153:12: no matching function for call to v4f_map
BROKEN_powerpc64=	fails to build: cc1plus: unrecognized command line option -std=c++11

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	moddevices
GH_TAGNAME=	072e2fe

post-patch:
	@${REINPLACE_CMD} -e "s|__APPLE__|__FreeBSD__|" \
		${WRKSRC}/dsp/v4f_IIR2.h

.include <bsd.port.mk>

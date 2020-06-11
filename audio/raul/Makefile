# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	raul
PORTVERSION=	0.8.0.20191209
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Realtime modular synthesizer and/or effects processor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/fftw3.h:math/fftw3

USES=		compiler:c++11-lang waf
USE_GITHUB=	yes
GH_ACCOUNT=	drobilla
GH_TAGNAME=	e87bb398f025912fb989a09f1450b838b251aea1
GH_TUPLE=	drobilla:autowaf:c87cc53:waflib/waflib

NO_ARCH=	yes

.include <bsd.port.mk>

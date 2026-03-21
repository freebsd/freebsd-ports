PORTNAME=	iverilog
PORTVERSION=	13.0
CATEGORIES=	cad

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Verilog simulation and synthesis tool
WWW=		https://steveicarus.github.io/iverilog/

LICENSE=	GPLv2

BUILD_DEPENDS=	gperf:devel/gperf

USES=		bison compiler:c++11-lang gmake readline

USE_GITHUB=	yes
GH_ACCOUNT=	steveicarus
GH_TAGNAME=	v13_0

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-suffix

.include <bsd.port.mk>

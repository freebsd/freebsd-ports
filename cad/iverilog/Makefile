PORTNAME=	iverilog
DISTVERSIONPREFIX=	v
DISTVERSION=	12_0
PORTREVISION=	1
CATEGORIES=	cad

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Verilog simulation and synthesis tool
WWW=		https://steveicarus.github.io/iverilog/

LICENSE=	GPLv2

BUILD_DEPENDS=	autoconf:devel/autoconf \
		gperf:devel/gperf

USES=		bison compiler:c++11-lang gmake readline

USE_GITHUB=	yes
GH_ACCOUNT=	steveicarus

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-suffix
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

pre-configure:
	@cd ${WRKSRC} && sh autoconf.sh

.include <bsd.port.mk>

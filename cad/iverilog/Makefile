PORTNAME=	iverilog
DISTVERSION=	12.0
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}
DISTNAME=	verilog-${DISTVERSION}

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Verilog simulation and synthesis tool
WWW=		https://steveicarus.github.io/iverilog/

LICENSE=	GPLv2

BUILD_DEPENDS=	gperf:devel/gperf

USES=		bison compiler:c++11-lang gmake readline

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-suffix

.include <bsd.port.mk>

# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iverilog
PORTVERSION=	10.1.1
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v${PORTVERSION:C,\.[0-9]\.[0-9]$,,}/
DISTNAME=	verilog-${PORTVERSION}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Verilog simulation and synthesis tool

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-suffix
USES=		bison gmake

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>

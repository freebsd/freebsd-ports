# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iverilog
PORTVERSION=	0.9.7
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v${PORTVERSION:C,\.[0-9]$,,}/ \
		ftp://ftp.geda.seul.org/pub/geda/dist/
DISTNAME=	verilog-${PORTVERSION}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	A Verilog simulation and synthesis tool

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		bison gmake

CONFIGURE_ARGS=	--disable-suffix

.include <bsd.port.mk>

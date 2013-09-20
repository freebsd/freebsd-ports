# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iverilog
PORTVERSION=	0.9.6
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v${PORTVERSION:C,\.[0-9]$,,}/ \
		ftp://ftp.geda.seul.org/pub/geda/dist/
DISTNAME=	verilog-${PORTVERSION}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	A Verilog simulation and synthesis tool

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		bison
USE_GMAKE=	yes

CONFIGURE_ARGS=	--disable-suffix

MAN1=		iverilog-vpi.1 iverilog.1 vvp.1

NO_STAGE=	yes
.include <bsd.port.mk>

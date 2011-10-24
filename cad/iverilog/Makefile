# ex:ts=8
# New ports collection makefile for:	iverilog
# Date created:		Feb 13, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iverilog
PORTVERSION=	0.9.2
PORTREVISION=	0
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v${PORTVERSION:C,\.[0-9]$,,}/ \
		ftp://ftp.geda.seul.org/pub/geda/dist/
DISTNAME=	verilog-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Verilog simulation and synthesis tool

GNU_CONFIGURE=	yes
USE_BISON=	build
USE_GMAKE=	yes

CONFIGURE_ARGS=	--disable-suffix

MAN1=		iverilog-vpi.1 iverilog.1 vvp.1

.include <bsd.port.mk>

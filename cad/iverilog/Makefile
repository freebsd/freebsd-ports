# ex:ts=8
# New ports collection makefile for:	iverilog
# Date created:		Feb 13, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iverilog
PORTVERSION=	0.8
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v$(PORTVERSION)/
DISTNAME=	verilog-$(PORTVERSION)

MAINTAINER=	watchman@ludd.luth.se
COMMENT=	A Verilog simulation and synthesis tool

USE_BISON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		iverilog-vpi.1 iverilog.1 vvp.1 iverilog-fpga.1

.include <bsd.port.mk>

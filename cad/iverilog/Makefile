# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iverilog
PORTVERSION=	10.1
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v${PORTVERSION:C,\.[0-9]$,,}/
DISTNAME=	verilog-${PORTVERSION}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Verilog simulation and synthesis tool

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		bison gmake

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>=0:textproc/flex
CONFIGURE_ENV+=	ac_cv_prog_LEX="${LOCALBASE}/bin/flex"
.endif

CONFIGURE_ARGS=	--disable-suffix

.include <bsd.port.mk>

# Created by: Johnny Sorocil <jsorocil@gmail.com>
# $FreeBSD$

PORTNAME=	lattice-ice40-tools
PORTVERSION=	g20181021
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source tools for Lattice iCE40 FPGAs

RUN_DEPENDS=	abc:cad/abc \
		arachne-pnr:devel/arachne-pnr \
		icepack:devel/icestorm \
		yosys:cad/yosys

USES=		metaport

OPTIONS_DEFINE=	EXAMPLES

EXAMPLES_DESC=	Build examples for Olimex iCE40 FPGA boards

EXAMPLES_RUN_DEPENDS=	lattice-ice40-examples-hx1k>=g0:devel/lattice-ice40-examples-hx1k \
			lattice-ice40-examples-hx8k>=g0:devel/lattice-ice40-examples-hx8k

.include <bsd.port.mk>

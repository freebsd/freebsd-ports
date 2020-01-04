# Created by: Johnny Sorocil <jsorocil@gmail.com>
# $FreeBSD$

PORTNAME=	lattice-ice40-examples-hx1k
PORTVERSION=	g20180310
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lattice iCE40 FPGA examples for the Olimex HX1K board

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	abc:cad/abc \
		arachne-pnr:devel/arachne-pnr \
		icepack:devel/icestorm \
		yosys:cad/yosys

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	OLIMEX
GH_PROJECT=	iCE40HX1K-EVB
GH_TAGNAME=	69df5a7fc2daa8f00a984426b721499f6df22492

EXAMPLESDIR=	${PREFIX}/share/examples/lattice-ice40-olimex
NO_ARCH=	yes

do-build:
	${DO_MAKE_BUILD} -C ${WRKSRC}/demo/ice40hx1k-evb
	${DO_MAKE_BUILD} -C ${WRKSRC}/demo/ice40-io-video

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/ice40hx1k-evb/example.v \
		${STAGEDIR}${EXAMPLESDIR}/ice40hx1k-blinky.v
	${INSTALL_DATA} ${WRKSRC}/demo/ice40hx1k-evb/example.rpt \
		${STAGEDIR}${EXAMPLESDIR}/ice40hx1k-blinky.rpt
	${INSTALL_DATA} ${WRKSRC}/demo/ice40hx1k-evb/example.bin \
		${STAGEDIR}${EXAMPLESDIR}/ice40hx1k-blinky.bin
	${INSTALL_DATA} ${WRKSRC}/demo/ice40-io-video/example.v \
		${STAGEDIR}${EXAMPLESDIR}/ice40hx1k-vga-ps2.v
	${INSTALL_DATA} ${WRKSRC}/demo/ice40-io-video/example.rpt \
		${STAGEDIR}${EXAMPLESDIR}/ice40hx1k-vga-ps2.rpt
	${INSTALL_DATA} ${WRKSRC}/demo/ice40-io-video/example.bin \
		${STAGEDIR}${EXAMPLESDIR}/ice40hx1k-vga-ps2.bin

.include <bsd.port.mk>

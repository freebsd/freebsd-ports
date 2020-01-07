# $FreeBSD$

PORTNAME=	ujprog
DISTVERSION=	g20191117
CATEGORIES=	comms

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ULX2S/ULX3S FPGA JTAG programmer

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libftdi.so:devel/libftdi

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	f32c
GH_PROJECT=	tools
GH_TAGNAME=	0698352b0e912caa9b8371b8f692e19aac547a69
USE_CSTD=	c99

ALL_TARGET=	ujprog flash

WRKSRC_SUBDIR=	${PORTNAME}

MAKEFILE=	Makefile.bsd

MAKE_ARGS=	INCLUDES="`libftdi-config --cflags`" FTLIB="`libftdi-config --libs`"

PLIST_FILES=	bin/ujprog \
		bin/ft232r_flash

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ujprog ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ft232r_flash ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

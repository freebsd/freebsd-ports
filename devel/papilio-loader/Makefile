# Created by: mr@freebsd.org
# $FreeBSD$

PORTNAME=	papilio-loader
PORTVERSION=	2.8
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Load bit files to the Open Source Papilio FPGA boards

LICENSE=	GPLv2

LIB_DEPENDS=	libftdi1.so:devel/libftdi1

USE_GITHUB=	yes
GH_ACCOUNT=	GadgetFactory
GH_PROJECT=	Papilio-Loader
GH_TAGNAME=	dd111c4
WRKSRC_SUBDIR=	papilio-prog

USES=		autoreconf:autoconf pkgconfig gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	libftdi1_CFLAGS="-I ${LOCALBASE}/include/libftdi1"
CONFIGURE_ENV+=	libftdi1_LIBS="-L ${LOCALBASE}/lib -lftdi1"

post-patch:
	@echo "${DATADIR}"
	${CP} ${FILESDIR}/Papilio_Programmer.sh ${WRKSRC}
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/Papilio_Programmer.sh

BITFILES=	bscan_spi_xc3s250e.bit bscan_spi_xc3s500e.bit bscan_spi_lx9.bit
post-install:
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/Papilio_Programmer.sh ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for BITFILE in ${BITFILES}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${BITFILE} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>

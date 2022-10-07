PORTNAME=	xc3sprog
PORTVERSION=	g20221005
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	darius@dons.net.au
COMMENT=	Free programmer for Xilinx FPGA and flash chips
WWW=		https://github.com/DanielO/xc3sprog

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libftdi.so:devel/libftdi
RUN_DEPENDS=	${LOCALBASE}/sbin/fxload:misc/fxload

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	DanielO
GH_TAGNAME=	426b763

post-install:
	${INSTALL_MAN} ${WRKSRC}/xc3sprog.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

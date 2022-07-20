PORTNAME=	iec16022
DISTVERSION=	0.3.1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/rdoeffinger/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Create 2D barcodes, also known as DataMatrix

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:devel/popt

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CFLAGS+=	-fPIC

.include <bsd.port.mk>

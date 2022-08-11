PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	1.0.5
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Audio component collection and framework

LICENSE=	GPLv2+

LIB_DEPENDS=	libcdio.so:sysutils/libcdio \
		libcdio_cdda.so:sysutils/libcdio-paranoia \
		libexpat.so:textproc/expat2 \
		libsmooth-0.9.so:devel/smooth \
		liburiparser.so:net/uriparser \
		libxspf.so:multimedia/libxspf

USES=		gmake localbase
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	enzo1982
GH_PROJECT=	BoCA
MAKE_ARGS=	config=systemlibxspf USE_WINE=False

post-patch:
	@${REINPLACE_CMD} -e 's,INSTALL_DATA,BSD_INSTALL_LIB,' \
		${WRKSRC}/Makefile-commands ${WRKSRC}/runtime/Makefile

.include <bsd.port.mk>

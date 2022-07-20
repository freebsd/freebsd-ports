PORTNAME=	klavaro
PORTVERSION=	3.11
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Touchtyping trainer

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gettext gmake gnome iconv pkgconfig tar:bzip2
USE_GNOME=	cairo gtk30 intlhack
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-rdynamic
LIBS+=		-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes

post-extract:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' \
		${WRKSRC}/data/klavaro.desktop.in

pre-build:
	@${REINPLACE_CMD} -e 's|^am__append_1|#am__append_1|' \
		${WRKSRC}/src/Makefile

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>

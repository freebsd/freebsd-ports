PORTNAME=	klavaro
PORTVERSION=	3.14
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Touchtyping trainer
WWW=		http://klavaro.sourceforge.net/

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgtkdatabox.so:x11-toolkits/gtkdatabox

USES=		gettext gmake gnome iconv localbase pkgconfig tar:bzip2
USE_GNOME=	cairo gtk30 intlhack
USE_LDCONFIG=	yes

LDFLAGS+=	-rdynamic

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

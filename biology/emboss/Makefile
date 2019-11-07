# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	emboss
PORTVERSION=	6.6.0
PORTREVISION=	3
CATEGORIES=	biology
MASTER_SITES=	ftp://emboss.open-bio.org/pub/EMBOSS/
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Collection of open source tools for genetic sequence analysis

LICENSE=	GPLv2

BUILD_DEPENDS=	clustalw:biology/clustalw \
		primer3:biology/primer3
LIB_DEPENDS=	libgd.so:graphics/gd \
		libpng.so:graphics/png

CONFLICTS=	qmail-ldap-[0-9]* digest-[0-9]*

PREFIX?=	${LOCALBASE}/emboss
NO_MTREE=	yes
USES=		gmake libtool iconv
USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PREFIX=${PREFIX} DATADIR=${DATADIR}
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=${ICONV_CONFIGURE_ARG}
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/${PORTNAME:tu}/doc
DATADIR=	${PREFIX}/share/${PORTNAME:tu}

OPTIONS_DEFINE=	DOCS X11
OPTIONS_DEFAULT=	X11
DOCS_CONFIGURE_ON=	--with-docroot=${DOCSDIR}
X11_USES=	motif xorg
X11_USE=	XORG=x11
X11_LIB_DEPENDS=	libgd.so:graphics/gd \
		libpng.so:graphics/png
X11_CONFIGURE_OFF=	--without-x

CONFIG_FILE=	${WRKSRC}/emboss/emboss.default.template

post-patch:
	@${REINPLACE_CMD} -e 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/configure

pre-install:
	@ ${REINPLACE_CMD} -e 's#%%DATADIR%%#${PREFIX}/share/${PORTNAME:tu}#' ${CONFIG_FILE}

post-install:
	${INSTALL_DATA} ${CONFIG_FILE} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

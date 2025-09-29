PORTNAME=	tumble
DISTVERSIONPREFIX=	v
DISTVERSION=	0.38
PORTREVISION=	3
CATEGORIES=	graphics print

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Creates a PDF file from image files
WWW=		http://tumble.brouhaha.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	historical tool, use imagemagick instead
EXPIRATION_DATE=	2025-12-31

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libnetpbm.so:graphics/netpbm

USES=		bison gmake jpeg localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	brouhaha

CFLAGS+=	-I${LOCALBASE}/include/netpbm

PLIST_FILES=	bin/tumble
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} tumble \
		${STAGEDIR}${PREFIX}/bin)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

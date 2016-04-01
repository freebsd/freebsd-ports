# Created by: Rob Farmer <rfarmer@predatorlabs.net>
# $FreeBSD$

PORTNAME=	tumble
PORTVERSION=	0.33
PORTREVISION=	4
CATEGORIES=	graphics print
MASTER_SITES=	http://tumble.brouhaha.com/download/ \
		http://www.sourcefiles.org/Graphics/Tools/Conversion/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates a PDF file from image files

LICENSE=	GPLv2

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libnetpbm.so:graphics/netpbm

USES=		bison gmake

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NOT_FOR_ARCHS=	powerpc sparc64
NOT_FOR_ARCHS_REASON=	Only works on little endian systems

PORTDOCS=	README
PLIST_FILES=	bin/tumble

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|^\(CFLAGS\) =.*|\1 := $$(CFLAGS)| ; \
		 s|^\(LDFLAGS\) =.*|\1 := $$(LDFLAGS)| ; \
		 s|-O3|| ; \
		 s|-lpbm|-lnetpbm| ; \
		 s|strip|true|' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} tumble \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

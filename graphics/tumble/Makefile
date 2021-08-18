# Created by: Rob Farmer <rfarmer@predatorlabs.net>

PORTNAME=	tumble
DISTVERSIONPREFIX=	v
DISTVERSION=	0.36
PORTREVISION=	1
CATEGORIES=	graphics print

MAINTAINER=	fuz@fuz.su
COMMENT=	Creates a PDF file from image files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=		mips mips64 powerpc powerpc64 powerpcspe sparc64
NOT_FOR_ARCHS_REASON=	Only works on little endian systems

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libnetpbm.so:graphics/netpbm

USES=		bison gmake jpeg localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	brouhaha

CFLAGS+=	-I${LOCALBASE}/include/netpbm

PLIST_FILES=	bin/tumble
PORTDOCS=	README

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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

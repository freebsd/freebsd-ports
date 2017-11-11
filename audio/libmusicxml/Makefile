# $FreeBSD$

PORTNAME=	libmusicxml
DISTVERSION=	3.11
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and tools for the MusicXML format

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm
GH_TAGNAME=	91347ae
USE_LDCONFIG=	yes
CMAKE_SOURCE_PATH=	${WRKSRC}/build

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

post-build-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/doc/presentation/libmusicxml2.pdf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

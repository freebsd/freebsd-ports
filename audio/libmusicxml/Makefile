# $FreeBSD$

PORTNAME=	libmusicxml
DISTVERSIONPREFIX=	v
DISTVERSION=	3.14-1
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g52654a71
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and tools for the MusicXML format

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cmake:outsource compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm
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

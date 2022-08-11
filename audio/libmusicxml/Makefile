PORTNAME=	libmusicxml
DISTVERSIONPREFIX=	v.
DISTVERSION=	3.22
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and tools for the MusicXML format

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cmake compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm

CMAKE_SOURCE_PATH=	${WRKSRC}/build

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

post-stage:
	@${RM} ${STAGEDIR}${PREFIX}/CHANGELOG.txt
	@${RM} ${STAGEDIR}${PREFIX}/README.html

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/doc/presentation/libmusicxml2.pdf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

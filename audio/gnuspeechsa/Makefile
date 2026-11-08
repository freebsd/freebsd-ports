PORTNAME=	gnuspeechsa
PORTVERSION=	0.1.5
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	GNU/gnuspeech

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Command line, or application-based speech output module of gnuspeech
WWW=		https://www.gnu.org/software/gnuspeech/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Abandoned upstream, does not build with CMake 4
EXPIRATION_DATE=2026-11-30

USES=		cmake compiler:c++11-lib

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

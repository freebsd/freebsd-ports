# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnuspeechsa
PORTVERSION=	0.1.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	GNU/gnuspeech

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Command line, or application-based speech output module of gnuspeech

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		Does not build: the clang compiler does not support -march=native
BROKEN_powerpc64=	Does not build: the clang compiler does not support -march=native

USES=		cmake compiler:c++11-lib

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

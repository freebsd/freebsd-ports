# Created by: Wes Peters <@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avra
PORTVERSION=	1.4.1
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Macro Assembler for Atmel AVR microcontrollers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	hsoft

USES=		gmake
MAKE_ENV=	TARGET_INCLUDE_PATH="${DATADIR}/includes"
TEST_TARGET=	check

PORTDOCS=	AUTHORS CHANGELOG.md README.md TODO USAGE.md
PORTEXAMPLES=	*
PORTDATA=	*
PLIST_FILES=	bin/avra

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/avra

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

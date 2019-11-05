# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cave9
PORTVERSION=	0.4.1.git20150408
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Gravity cave-exploration game

LICENSE=	GPLv3+ CC-BY-SA-3.0 CC-BY-2.5
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/data/README.txt # CC licenses
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING.txt

USE_GITHUB=	yes
GH_ACCOUNT=	bart9h
GH_TAGNAME=	e6896eb

USES=		gl gmake sdl
USE_SDL=	sdl ttf image
USE_GL=		gl glu

BUILD_WRKSRC=	${WRKSRC}/src

MAKEFILE=	GNUmakefile
CFLAGS+=	-DDATADIR=\\\"${DATADIR}\\\"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="${PORTNAME}" \
		"" \
		"${DATADIR}/icon.png" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cave9 ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for d in wav png ttf jpg
	${INSTALL_DATA} ${WRKSRC}/data/*.$d ${STAGEDIR}${DATADIR}/
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS.txt ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

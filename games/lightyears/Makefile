# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lightyears
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.jwhitham.org/20kly/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Steampunk-themed strategy game: manage a steam supply network

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYGAME}

USES=		python:2.7 shebangfix tar:bz2
SHEBANG_FILES=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

PORTDOCS=	README.txt THANKS.txt
PORTDATA=	*
PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="20,000 Light Years Into Space" \
		"" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" \
		"Game;StrategyGame;" \
		""

post-patch:
	@${REINPLACE_CMD} -e '/^LIGHTYEARS_DIR =/ s|".*"|"${DATADIR}"|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "audio code data manual" ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/32.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>

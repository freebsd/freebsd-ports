PORTNAME=	pathological
PORTVERSION=	1.1.3
PORTREVISION=	18
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Enriched clone of the game "Logical"
WWW=		https://pathological.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYGAME}

OPTIONS_DEFINE=	DOCS

USES=		python shebangfix
SHEBANG_FILES=	pathological.py
NO_BUILD=	yes
NO_ARCH=	yes

DOC_FILES=	favicon.ico index.html

DESKTOP_ENTRIES="Pathological" \
		"Logic game" \
		"${DATADIR}/pathological.ico" \
		"pathological" \
		"Game;LogicGame;" \
		false

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}; tar -cf - circuits graphics music sounds pathological.ico pathological.py pathological.xpm) | \
		(cd ${STAGEDIR}${DATADIR}; tar --unlink -xf -)
	@${PRINTF} "#!/bin/sh\ncd ${DATADIR} && \
		exec ${PYTHON_CMD} ${DATADIR}/pathological.py\n" > ${WRKDIR}/pathological.sh
	${INSTALL_SCRIPT} ${WRKDIR}/pathological.sh \
		${STAGEDIR}${PREFIX}/bin/pathological
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6.gz ${STAGEDIR}${PREFIX}/share/man/man6
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S|^|${WRKSRC}/html/|g} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

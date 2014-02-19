# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	ski
PORTVERSION=	6.7
CATEGORIES=	games python
MASTER_SITES=	http://catb.org/~esr/ski/
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Skiing simulation with curses interface in python

LICENSE=	BSD3CLAUSE

USE_PYTHON_RUN=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|' \
		${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${STAGEDIR}${PREFIX}/man/man6/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

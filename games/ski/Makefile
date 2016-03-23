# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	ski
PORTVERSION=	6.11
CATEGORIES=	games python
MASTER_SITES=	http://catb.org/~esr/ski/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Skiing simulation with curses interface in python

LICENSE=	BSD3CLAUSE

USES=		python:3.2+:run
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz \
		share/applications/${PORTNAME}.desktop \
		share/appdata/${PORTNAME}.xml \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	NEWS README
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|; \
		s|/usr/share/man|${PREFIX}/man|; \
		s|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|' \
		${WRKSRC}/${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# Created by: schmidtcarl@earthlink.net
# $FreeBSD$

PORTNAME=	charm
PORTVERSION=	1.9.2
CATEGORIES=	deskutils net
MASTER_SITES=	SF/lj${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	seawolf@marinewolf.net
COMMENT=	Menu-driven python-based livejournal client

LICENSE=	GPLv2

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's,share/doc/charm,${DOCSDIR},' ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e 's,1.9.1,1.9.2,' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES.charm ${STAGEDIR}${DOCSDIR}/CHANGES
	${INSTALL_DATA} ${WRKSRC}/README.charm ${STAGEDIR}${DOCSDIR}/README
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.charmrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

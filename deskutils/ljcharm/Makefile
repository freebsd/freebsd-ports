# Created by: schmidtcarl@earthlink.net
# $FreeBSD$

PORTNAME=	charm
PORTVERSION=	1.9.2
PORTREVISION=	2
CATEGORIES=	deskutils net
MASTER_SITES=	SF/lj${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	seawolf@marinewolf.net
COMMENT=	Menu-driven python-based livejournal client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

USES=		python:2.7
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES.charm ${STAGEDIR}${DOCSDIR}/CHANGES
	${INSTALL_DATA} ${WRKSRC}/README.charm ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/charm.html ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.charmrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

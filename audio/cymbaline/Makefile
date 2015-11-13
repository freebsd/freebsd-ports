# Created by: ijliao
# $FreeBSD$

PORTNAME=	cymbaline
PORTVERSION=	1.3e
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://www.silmarill.org/files/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Console frontend for py-mad

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/aomodule.so:${PORTSDIR}/audio/py-ao \
		${PYTHON_SITELIBDIR}/madmodule.so:${PORTSDIR}/audio/py-mad

BROKEN=		Fails to fetch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
USES=		python
USE_PYTHON=	distutils autoplist

PLIST_FILES=	bin/cymbaline

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-install:
	${LN} -sf cymbaline.py ${STAGEDIR}${PREFIX}/bin/cymbaline
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

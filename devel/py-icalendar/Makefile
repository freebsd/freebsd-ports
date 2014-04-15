# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icalendar
PORTVERSION=	3.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	Parser and generator of iCalender files for Python

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz

USE_PYTHON=	2
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.rst ${WRKSRC}/docs/changelog.rst ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>

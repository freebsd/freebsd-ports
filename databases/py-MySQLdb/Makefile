# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MySQLdb
PORTVERSION=	1.2.5
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Access a MySQL database through Python

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL-2.0

USES=		mysql python:2
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	farcepest
GH_PROJECT=	${PORTNAME}1

CONFLICTS=	${PYTHON_PKGNAMEPREFIX}-MySQLdb5[0-9]-[0-9]* \
		${PYTHON_PKGNAMEPREFIX}-mysqlclient-[0-9]*

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=		DOCS MYSQLCLIENT_R
OPTIONS_DEFAULT=	MYSQLCLIENT_R
MYSQLCLIENT_R_DESC=	Use libmysqlclient_r (thread safe)

pre-configure-MYSQLCLIENT_R-on:
	${REINPLACE_CMD} -e '/threadsafe = / s|True|False|' ${WRKSRC}/site.cfg

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_mysql.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

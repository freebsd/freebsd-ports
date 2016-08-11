# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MySQLdb
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.2.5
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Access a MySQL database through Python

USES=		python:2 mysql
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	farcepest
GH_PROJECT=	${PORTNAME}1

CONFLICTS=	py*-MySQLdb-[0-9]* py*-MySQLdb5[0-9]-[0-9]* py*-mysqlclient-[0-9]*

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=		DOCS MYSQLCLIENT_R
OPTIONS_DEFAULT=	MYSQLCLIENT_R
MYSQLCLIENT_R_DESC=	Use libmysqlclient_r (thread safe)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQLCLIENT_R}
pre-configure:
	@${REINPLACE_CMD} -E -e "s|(threadsafe.*)True|\1 False|" \
		${WRKSRC}/site.cfg
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

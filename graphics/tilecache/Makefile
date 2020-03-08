# Created by: joris
# $FreeBSD$

PORTNAME=	tilecache
PORTVERSION=	2.11
PORTREVISION=	3
CATEGORIES=	graphics python geography www
MASTER_SITES=	http://tilecache.org/

MAINTAINER=	joris.dedieu@gmail.com
COMMENT=	Python-based WMS-C/TMS server

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flup6>0:www/py-flup6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Paste>0:www/py-paste@${PY_FLAVOR}

USES=		python:2.7 shebangfix
USE_PYTHON=	distutils autoplist
SHEBANG_FILES=	tilecache.cgi tilecache.fcgi

FILES_ETC=	TileCache/Service.py setup.py tilecache_install_config.py

post-patch:
	@cd ${WRKSRC}; \
	${REINPLACE_CMD} -e 's|/etc|${ETCDIR}|' ${FILES_ETC};

pre-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/cgi-bin
	${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|' ${WRKSRC}/tilecache.cgi
	${INSTALL_SCRIPT} ${WRKSRC}/tilecache.cgi ${STAGEDIR}${PREFIX}/www/cgi-bin/tilecache.cgi
	${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|' ${WRKSRC}/tilecache.fcgi
	${INSTALL_SCRIPT} ${WRKSRC}/tilecache.fcgi ${STAGEDIR}${PREFIX}/www/cgi-bin/tilecache.fcgi
	${INSTALL_DATA} ${WRKSRC}/tilecache.cfg ${STAGEDIR}${ETCDIR}/tilecache.cfg.sample

.include <bsd.port.mk>

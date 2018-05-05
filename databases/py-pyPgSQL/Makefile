# Created by: Gerhard Haering <gerhard.haering@gmx.de>
# $FreeBSD$

PORTNAME=	pyPgSQL
PORTVERSION=	2.5.1
PORTREVISION=	4
CATEGORIES=	databases python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python DB-API 2 compliant library for using PostgreSQL databases

BROKEN=		Invalid checksum
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06

RUN_DEPENDS=	${DATETIME_DEP}:lang/py-mx-base

USES=	pgsql python:2.7
USE_PYTHON=	distutils

DOCS=		Announce ChangeLog README README.html
EXAMPLES=	examples/*.py

DATETIME_DEP=	${PYTHON_SITELIBDIR}/mx/DateTime/__init__.py

OPTIONS_DEFINE=	BYTEA_CONN EXAMPLES DOCS
OPTIONS_DEFAULT=	BYTEA_CONN
BYTEA_CONN_DESC=	Apply Bytea connection patch

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBYTEA_CONN}
PATCH_SITES=	http://sourceforge.net/tracker/download.php?group_id=16528&atid=316528&file_id=273956&aid=1939119/
PATCHFILES=	pyPgSQL-patch_byteaconn
.endif

DOCSDIR=	${PREFIX}/share/doc/py-pyPgSQL
EXAMPLESDIR=	${PREFIX}/share/examples/py-pyPgSQL

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>

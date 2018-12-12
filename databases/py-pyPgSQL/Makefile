# Created by: Gerhard Haering <gerhard.haering@gmx.de>
# $FreeBSD$

PORTNAME=	pyPgSQL
PORTVERSION=	2.5.1
PORTREVISION=	6
CATEGORIES=	databases python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Python DB-API 2.0 compliant interface to PostgreSQL

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mx-base>0:lang/py-mx-base@${PY_FLAVOR}

USES=		pgsql python:2.7
USE_PYTHON=	distutils autoplist

DOCS=		Announce ChangeLog README README.html
EXAMPLES=	examples/*.py

OPTIONS_DEFINE=		BYTEA_CONN EXAMPLES DOCS
OPTIONS_DEFAULT=	BYTEA_CONN

BYTEA_CONN_DESC=	Apply Bytea connection patch
BYTEA_CONN_VARS=	PATCH_SITES=	https://sourceforge.net/p/pypgsql/patches/_discuss/thread/c9fcb468/43b1/attachment/ \
			PATCHFILES=	patch-byteaconn

.include <bsd.port.options.mk>

DOCSDIR=	${PREFIX}/share/doc/py-pyPgSQL
EXAMPLESDIR=	${PREFIX}/share/examples/py-pyPgSQL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyPgSQL/libpq/libpqmodule.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>

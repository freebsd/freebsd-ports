# New ports collection makefile for:   py-PySQLite
# Date created:                        02 Oct 2002
# Whom:                                Gerhard Haering <gerhard.haering@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	pysqlite
PORTVERSION=	2.3.5
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/pysqlite/releases/${PORTVERSION:C/\.[0-9]$//}/${PORTVERSION}/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A DB-API v2 Python library for the SQLite 3 embedded SQL engine

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3

DEPRECATED=	unmaintained upstream, only useful for python2.4 or less, no consumers in the ports tree
EXPIRATION_DATE=	2011-12-11

CONFLICTS=	py*-pysqlite-2.[0-24-9].*

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_BUILDARGS=	build_ext -I${LOCALBASE}/include -L${LOCALBASE}/lib
DOCSBASE=	share/doc/py-${PORTNAME}2
DOCSDIR=	${PREFIX}/${DOCSBASE}

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e "s|/usr|${PREFIX}|" ${WRKSRC}/setup.cfg
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e "s|pysqlite2-doc|${DOCSBASE}|" \
		-e "s/.*(cmdclass|extras_require) =.*//" \
			${WRKSRC}/setup.py
.else
	@${REINPLACE_CMD} -E -e "s/.*(cmdclass|extras_require) =.*//" \
		-e "s|data_files = \[.*|data_files = []|" \
		-e "s|.*glob.glob\(.*\).*||" \
		-e "s|.*pysqlite2-doc/code.*||" \
			${WRKSRC}/setup.py
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/code
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
.endif

.include <bsd.port.mk>

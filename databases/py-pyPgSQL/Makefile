# New ports collection makefile for:   py-pypgsql
# Date created:                        01 Nov 2001
# Whom:                                Gerhard Haering <gerhard.haering@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	pyPgSQL
PORTVERSION=	2.2
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pypgsql
PKGNAMEPREFIX=	py-
DISTNAME=	pypgsql-${PORTVERSION}

MAINTAINER=	gerhard.haering@gmx.de

RUN_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base
LIB_DEPENDS=	pq.2:${PORTSDIR}/databases/postgresql7

WRKSRC=		${WRKDIR}/pypgsql
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	YES

DOCS=		README

PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}

DATETIME_DEP=	${PYTHON_SITELIBDIR}/mx/DateTime/__init__.py

DOCSDIR=	${PREFIX}/share/doc/py-pyPgSQL

post-patch:
	${REINPLACE_CMD} -e 's^/usr/local^${LOCALBASE}^g' ${WRKSRC}/setup.py

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

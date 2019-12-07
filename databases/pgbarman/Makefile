# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	barman
DISTVERSION=	2.10
CATEGORIES=	databases
MASTER_SITES=	SF/${PKGNAMEPREFIX}${PORTNAME}/${DISTVERSION}
PKGNAMEPREFIX=	pg
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} manual.pdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Backup and recovery manager for PostgreSQL

LICENSE=	GPLv3

RUN_DEPENDS=	rsync:net/rsync						\
		${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}argh>=0.21.2:devel/py-argh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}argcomplete>0:devel/py-argcomplete@${PY_FLAVOR}

USES=		pgsql python
USE_PYTHON=	autoplist distutils concurrent optsuffix

WANT_PGSQL=	client
NO_ARCH=	yes

USERS=		barman
GROUPS=		barman

PORTDOCS=	manual.pdf

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${PGSQL_VER:M9\.[12345]}
PGUSER=		pgsql
.else
PGUSER=		postgres
.endif

post-extract:
	${CP} ${DISTDIR}/${PORTDOCS} ${WRKDIR}/

post-patch:
	${SED} -i -e "s@%%PREFIX%%@${PREFIX}@" ${WRKSRC}/barman/config.py
	${SED} -i -e "s@%%PREFIX%%@${PREFIX}@" ${WRKSRC}/doc/barman.conf
	${SED} -i -e "s@%%PGUSER%%@${PGUSER}@" ${WRKSRC}/doc/barman.5

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/barman.conf \
		${STAGEDIR}${ETCDIR}/barman.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>

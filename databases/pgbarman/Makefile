# Created by: Matthew Seaman

PORTNAME=		barman
DISTVERSIONPREFIX=	release/
DISTVERSION=		2.17
CATEGORIES=		databases
PKGNAMEPREFIX=		pg
PKGNAMESUFFIX=		${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Backup and recovery manager for PostgreSQL

LICENSE=	GPLv3

RUN_DEPENDS=	rsync:net/rsync									\
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.4.2:databases/py-psycopg2@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR}		\
		${PYTHON_PKGNAMEPREFIX}argcomplete>0:devel/py-argcomplete@${PY_FLAVOR}

USES=		pgsql python:3.7+
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	EnterpriseDB

WANT_PGSQL=	client
NO_ARCH=	yes

USERS=		barman
GROUPS=		barman

OPTIONS_DEFINE=		DOCS

DOCS_DESC=	Install PDF manual
DOCS_VARS=	PORTDOCS=barman-${DISTVERSION}-manual.pdf \
		MASTER_SITES+=https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/release%2F${DISTVERSION}/:docs \
		DISTFILES+=barman-${DISTVERSION}-manual.pdf:docs \
		EXTRACT_ONLY=${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.pre.mk>

.if ${PGSQL_VER:M9\.[12345]}
PGUSER=		pgsql
.else
PGUSER=		postgres
.endif

post-extract-DOCS-on:
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

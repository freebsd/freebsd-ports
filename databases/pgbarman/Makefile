# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	barman
DISTVERSION=	2.3
CATEGORIES=	databases
MASTER_SITES=	SF/${PKGNAMEPREFIX}${PORTNAME}/${DISTVERSION}
PKGNAMEPREFIX=	pg
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} tutorial.pdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Backup and recovery manager for PostgreSQL

LICENSE=	GPLv3

RUN_DEPENDS=	rsync:net/rsync						\
		${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil@${FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}argh>=0.21.2:devel/py-argh@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}argcomplete>0:devel/py-argcomplete@${FLAVOR}

NO_ARCH=	yes

USERS=		barman
GROUPS=		barman

USES=		pgsql python
WANT_PGSQL=	client
USE_PYTHON=	autoplist distutils concurrent optsuffix

PORTDOCS=	tutorial.pdf

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
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/barman.conf ${STAGEDIR}${ETCDIR}/barman.conf.sample

.include <bsd.port.post.mk>

# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	barman
DISTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF/${PKGNAMEPREFIX}${PORTNAME}/${DISTVERSION}
PKGNAMEPREFIX=	pg
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} tutorial.pdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Backup and recovery manager for PostgreSQL

LICENSE=	GPLv3

RUN_DEPENDS=	rsync:net/rsync						\
		${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2	\
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil	\
		${PYTHON_PKGNAMEPREFIX}argh>=0.21.2:devel/py-argh \
		${PYTHON_PKGNAMEPREFIX}argcomplete>0:devel/py-argcomplete

NO_ARCH=	yes

USERS=		barman
GROUPS=		barman

USES=		pgsql python
WANT_PGSQL=	client
USE_PYTHON=	autoplist distutils

PORTDOCS=	tutorial.pdf

post-extract:
	${CP} ${DISTDIR}/${PORTDOCS} ${WRKDIR}/

post-patch:
	${SED} -i -e "s@%%PREFIX%%@${PREFIX}@" ${WRKSRC}/barman/config.py

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/barman.conf ${STAGEDIR}${ETCDIR}/barman.conf.sample

.include <bsd.port.mk>

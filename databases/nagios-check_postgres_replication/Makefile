# $FreeBSD$

PORTNAME=	check_postgres_replication
PORTVERSION=	2010.12.16
CATEGORIES=	databases python
MASTER_SITES=	https://gist.github.com/raw/743942/4b9454d6aaf919fe77d15ecea09c7a001ae83b59/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMEPREFIX=	nagios-
DISTNAME=	check_postgres_replication.py
EXTRACT_SUFX=

MAINTAINER=	paul@it.ca
COMMENT=	Nagios plugin to check the lag between a postgresql replica and master

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nagiosplugin>=0:${PORTSDIR}/sysutils/py-nagiosplugin \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=0:${PORTSDIR}/databases/py-psycopg2

USE_PYTHON=	yes
USE_PGSQL=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

NO_STAGE=	yes
do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}

do-install:
	${MKDIR} ${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME} \
	    ${PREFIX}/libexec/nagios/${DISTNAME:S/.py//}

.include <bsd.port.mk>

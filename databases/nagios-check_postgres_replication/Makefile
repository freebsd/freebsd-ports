# $FreeBSD$

PORTNAME=	check_postgres_replication
PORTVERSION=	2010.12.16
CATEGORIES=	databases python
MASTER_SITES=	https://gist.github.com/raw/743942/4b9454d6aaf919fe77d15ecea09c7a001ae83b59/ \
		LOCAL/brooks
PKGNAMEPREFIX=	nagios-
DISTNAME=	check_postgres_replication.py
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios plugin to check the lag between a postgresql replica and master

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nagiosplugin>=0:${PORTSDIR}/sysutils/py-nagiosplugin \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=0:${PORTSDIR}/databases/py-psycopg2

USES=	pgsql python

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME} \
	    ${STAGEDIR}${PREFIX}/libexec/nagios/${DISTNAME:S/.py//}

.include <bsd.port.mk>

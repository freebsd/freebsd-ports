PORTNAME=	check_postgres_replication
PORTVERSION=	2010.12.16
PORTREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	https://gist.github.com/raw/743942/4b9454d6aaf919fe77d15ecea09c7a001ae83b59/ \
		LOCAL/brooks
PKGNAMEPREFIX=	nagios-
DISTNAME=	check_postgres_replication.py
EXTRACT_SUFX=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios plugin to check the lag between a postgresql replica and master

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nagiosplugin>=0:sysutils/py-nagiosplugin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR}

USES=		python shebangfix
SHEBANG_FILES=	check_postgres_replication.py
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	libexec/nagios/check_postgres_replication

do-extract:
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
		${STAGEDIR}${PREFIX}/libexec/nagios/${DISTNAME:S/.py//}

.include <bsd.port.mk>

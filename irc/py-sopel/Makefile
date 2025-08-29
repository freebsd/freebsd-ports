PORTNAME=	sopel
DISTVERSION=	8.0.4
CATEGORIES=	irc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Easy-to-use and highly extensible IRC Bot framework
WWW=		https://sopel.chat/

LICENSE=	EFLv2
LICENSE_GROUPS=	FSF GPL OSI
LICENSE_NAME=	Eiffel Forum License, version 2
LICENSE_FILE=	${FILESDIR}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}GeoIP2>0:net/py-GeoIP2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}praw>0:www/py-praw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy14>0:databases/py-sqlalchemy14@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.12:devel/py-xmltodict@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

USE_RC_SUBR=	sopel
NO_ARCH=	yes
SUB_FILES+=	pkg-message
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

USERS=		sopel
GROUPS=		sopel

PLIST_SUB=	GROUP="${GROUPS:[0]}" \
		USER="${USERS:[0]}"

post-install:
	@${MKDIR} ${STAGEDIR}/${ETCDIR}
	@${CP} ${FILESDIR}/sopel-default.cfg ${STAGEDIR}/${ETCDIR}/sopel-default.cfg.sample
.for dir in run log db
	@${MKDIR} ${STAGEDIR}/var/${dir}/sopel
.endfor
	@${MKDIR} ${STAGEDIR}/var/db/sopel/www
.for script in sopel sopel-config sopel-plugins
	${SED} -e "s|%%PYTHON_SHEBANG%%|#!${PYTHON_CMD}|" ${FILESDIR}/${script}.py \
		> ${STAGEDIR}${PREFIX}/bin/${script}
	${CHMOD} 555 ${STAGEDIR}${PREFIX}/bin/${script}
.endfor

.include <bsd.port.mk>

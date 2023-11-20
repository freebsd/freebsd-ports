PORTNAME=	sopel
DISTVERSION=	7.1.9
PORTREVISION=	1
CATEGORIES=	irc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Easy-to-use and highly extensible IRC Bot framework
WWW=		https://sopel.chat/

LICENSE=	EFLv2
LICENSE_GROUPS=	FSF GPL OSI
LICENSE_NAME=	Eiffel Forum License, version 2
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}GeoIP2>0:net/py-GeoIP2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}praw>0:www/py-praw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy13>0:databases/py-sqlalchemy13@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.12:devel/py-xmltodict@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

USE_RC_SUBR=	sopel
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
	${CP} ${FILESDIR}/${script}.py ${STAGEDIR}${PREFIX}/bin/${script}
	@${REINPLACE_CMD} -e "s|%%PYTHON_SHEBANG%%|#!${PYTHON_CMD}|" ${STAGEDIR}${PREFIX}/bin/${script}
	${CHMOD} 555 ${STAGEDIR}${PREFIX}/bin/${script}
.endfor

.include <bsd.port.mk>

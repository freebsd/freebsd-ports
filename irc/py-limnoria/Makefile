PORTNAME=	limnoria
DISTVERSION=	2022.1.1
CATEGORIES=	irc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Modified version of Supybot (IRC bot and framework)
WWW=		https://github.com/ProgVal/Limnoria

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=0:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	${PORTNAME}_project
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=		ECDSA PROXY SASL
OPTIONS_DEFAULT=	ECDSA ENCODING RSS SASL TIME

OPTIONS_GROUP=		EXTRAS
OPTIONS_GROUP_EXTRAS=	ENCODING GPG RSS TIME

OPTIONS_RADIO=		AKA
OPTIONS_RADIO_AKA=	SQLITE SQLALCHEMY

AKA_DESC=		AKA Plugin: SQL Backend (none = plugin disabled)
ECDSA_DESC=	ECDSA SASL authentication
ENCODING_DESC=	Web Plugin: Better encoding detection (via chardet)
EXTRAS_DESC=		Plugin Extras
GPG_DESC=	GPG Plugin: GnuPG Authentication
PROXY_DESC=	SOCKS Proxy connections
RSS_DESC=	RSS Plugin: Feed parsing (via feedparser)
SQLALCHEMY_DESC=	SQLAlchemy database support
TIME_DESC=	Time Plugin: Extra time features (via dateutil/pytz)

ECDSA_USE=		PYTHON=cryptography
ENCODING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR}
GPG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-gnupg>=0:security/py-python-gnupg@${PY_FLAVOR}
PROXY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysocks>=0:net/py-pysocks@${PY_FLAVOR}
RSS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=0:textproc/py-feedparser@${PY_FLAVOR}
SASL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyxmpp2_scram>=0:security/py-pyxmpp2_scram@${PY_FLAVOR}
SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy10>0:databases/py-sqlalchemy10@${PY_FLAVOR}
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
TIME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>=0:devel/py-python-dateutil@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR}

# Needs to be installed first to work.
do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${LOCALBASE}/bin/supybot-test \
		--no-network \
		--plugins-dir="./build/lib*/supybot/plugins/" \
		--disable-multiprocessing

.include <bsd.port.mk>

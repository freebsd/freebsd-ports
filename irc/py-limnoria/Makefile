# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	limnoria
PORTVERSION=	2019.09.08
CATEGORIES=	irc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Modified version of Supybot (IRC bot and framework)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=0:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR}

USES=		python # 2.6+
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	ProgVal
GH_PROJECT=	Limnoria
GH_TAGNAME=	master-2019-09-08

OPTIONS_DEFINE=		ECDSA PROXY
OPTIONS_DEFAULT=	ECDSA ENCODING RSS TIME

OPTIONS_GROUP=		EXTRAS
OPTIONS_GROUP_EXTRAS=	ENCODING GPG RSS TIME

OPTIONS_RADIO=		AKA
OPTIONS_RADIO_AKA=	SQLITE SQLALCHEMY

EXTRAS_DESC=		Plugin Extras
AKA_DESC=		AKA Plugin: SQL Backend (none = plugin disabled)

ECDSA_DESC=	ECDSA SASL authentication
PROXY_DESC=	SOCKS Proxy connections

ENCODING_DESC=	Web Plugin: Better encoding detection (via chardet)
GPG_DESC=	GPG Plugin: GnuPG Authentication
RSS_DESC=	RSS Plugin: Feed parsing (via feedparser)
TIME_DESC=	Time Plugin: Extra time features (via dateutil/pytz)

SQLALCHEMY_DESC=	SQLAlchemy database support

ECDSA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ecdsa>0:security/py-ecdsa@${PY_FLAVOR}
PROXY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysocks>=0:net/py-pysocks@${PY_FLAVOR}

ENCODING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR}
GPG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-gnupg>=0:security/py-python-gnupg@${PY_FLAVOR}
RSS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=0:textproc/py-feedparser@${PY_FLAVOR}
TIME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR}

SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy10>0:databases/py-sqlalchemy10@${PY_FLAVOR}

NO_ARCH=	yes

# Needs to be installed first to work.

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${LOCALBASE}/bin/supybot-test \
		--no-network \
		--plugins-dir="./build/lib*/supybot/plugins/" \
		--disable-multiprocessing

.include <bsd.port.mk>

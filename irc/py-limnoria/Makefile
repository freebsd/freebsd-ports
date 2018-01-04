# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	limnoria
PORTVERSION=	2016.06.29
CATEGORIES=	irc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Modified version of Supybot (IRC bot and framework)

LICENSE=	BSD3CLAUSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=0:textproc/py-feedparser@${FLAVOR}

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

ECDSA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ecdsa>0:security/py-ecdsa@${FLAVOR}
PROXY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysocks>=0:net/py-pysocks@${FLAVOR}

ENCODING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${FLAVOR}
GPG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-gnupg>=0:security/py-python-gnupg@${FLAVOR}
RSS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=0:textproc/py-feedparser@${FLAVOR}
TIME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${FLAVOR}

SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR}
SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy10>0:databases/py-sqlalchemy10@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# Needs to be installed first to work.

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${LOCALBASE}/bin/supybot-test \
		--no-network \
		--plugins-dir="./build/lib*/supybot/plugins/" \
		--disable-multiprocessing

.include <bsd.port.mk>

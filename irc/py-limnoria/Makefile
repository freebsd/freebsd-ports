# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	limnoria
PORTVERSION=	2015.12.12
CATEGORIES=	irc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Modified version of Supybot (an IRC bot and framework)

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=0:${PORTSDIR}/textproc/py-chardet \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}python-gnupg>=0:${PORTSDIR}/security/py-python-gnupg \
		${PYTHON_PKGNAMEPREFIX}feedparser>=0:${PORTSDIR}/textproc/py-feedparser \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}pysocks>=0:${PORTSDIR}/net/py-pysocks \
		${PYTHON_PKGNAMEPREFIX}ecdsa>0:${PORTSDIR}/security/py-ecdsa

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# Needs to be installed first to work.

do-test:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/supybot-test \
		--no-network \
		--plugins-dir="./build/lib*/supybot/plugins/" \
		--disable-multiprocessing

.include <bsd.port.mk>

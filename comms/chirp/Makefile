# $FreeBSD$

PORTNAME=	chirp
DISTVERSIONPREFIX=	daily-
DISTVERSION=	20200107
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	https://trac.chirp.danplanet.com/chirp_daily/daily-${DISTVERSION}/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Free, open-source tool for programming your amateur radio

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libxml2>0:textproc/py-libxml2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gtk2>0:x11-toolkits/py-gtk2@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		desktop-file-utils python:2.7
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

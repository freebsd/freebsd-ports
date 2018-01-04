# $FreeBSD$

PORTNAME=	chirp
PORTVERSION=	0.4.1.2017.02.22
CATEGORIES=	comms hamradio
MASTER_SITES=	http://trac.chirp.danplanet.com/chirp_daily/daily-${PORTVERSION:C/[0-9]+\.[0-9]+\.[0-9]+\.//:C/\.//g}/ \
		LOCAL/db
DISTNAME=	${PORTNAME}-daily-${PORTVERSION:C/[0-9]+\.[0-9]+\.[0-9]+\.//:C/\.//g}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Free, open-source tool for programming your amateur radio

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${CHIRP_DEPENDS}
RUN_DEPENDS=	${CHIRP_DEPENDS}
CHIRP_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libxml2>0:textproc/py-libxml2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}serial>0:comms/py-serial@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gtk2>0:x11-toolkits/py-gtk2@${FLAVOR}

USES=		desktop-file-utils gettext python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>

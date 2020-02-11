# Created by: Byung-Hee HWANG <bh@izb.knu.ac.kr>
# $FreeBSD$

PORTNAME=	mutagen
PORTVERSION=	1.42.0
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python-based audio metadata tag reader and writer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

NO_ARCH=	yes
USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_FILES=	tools/*

.include <bsd.port.mk>

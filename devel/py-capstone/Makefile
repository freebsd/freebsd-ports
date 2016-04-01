# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	capstone
PORTVERSION=	3.0.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python	# Conflicts with devel/capstone distfile

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python bindings for the Capstone Disassembly Engine

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

LIB_DEPENDS=	libcapstone.so:devel/capstone

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

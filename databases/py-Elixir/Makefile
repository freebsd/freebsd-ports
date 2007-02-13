# New ports collection makefile for:	py-Elixir
# Date created:		2007-02-13
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Elixir
PORTVERSION=	0.1.0
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	databases python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/E/Elixir/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Declarative Mapper for SQLAlchemy

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/${PYALCHEMY_EGG}:${PORTSDIR}/databases/py-sqlalchemy

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${PYELIXIR_EGG}

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYELIXIR_EGG=${PYELIXIR_EGG} \
		PYELIXIR_EGG_VER="${PORTNAME}==${PORTVERSION}"

PYELIXIR_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

.include <bsd.port.pre.mk>

PYALCHEMY_EGG!=	${MAKE} -f ${PORTSDIR}/databases/py-sqlalchemy/Makefile -V PYALCHEMY_EGG

.include <bsd.port.post.mk>

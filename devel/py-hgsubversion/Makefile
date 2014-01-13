# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	hgsubversion
PORTVERSION=	1.5.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Mercurial extension that allows using it as a Subversion client

LICENSE=	GPLv2

OPTIONS_DEFINE=	SUBVERTPY
OPTIONS_DEFAULT=SUBVERTPY
SUBVERTPY_DESC=	Use subvertpy python bindings

USE_PYTHON=	2
USE_PYDISTUTILS=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSUBVERTPY}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}subversion>=0:${PORTSDIR}/devel/py-subversion
.else
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}subvertpy>=0:${PORTSDIR}/devel/py-subvertpy
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[[:<:]]setuptools|distutils.core|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>

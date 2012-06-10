# New ports collection makefile for:	py-sanetime
# Date created:		2012-06-03
# Whom:			koobs <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	sanetime
PORTVERSION=	4.1.6
CATEGORIES=	devel python astro
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	A sane date/time Python interface, with Django support

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil<2.0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>2010:${PORTSDIR}/devel/py-pytz

LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

PYEASYINSTALL_INSTALLARGS=	-Z -q -O 1 -N -S ${PYTHON_SITELIBDIR} \
				-d ${PYEASYINSTALL_SITELIBDIR} \
				-s ${PYEASYINSTALL_BINDIR} \
				${WRKSRC}/dist/${PYEASYINSTALL_EGG}

.include <bsd.port.mk>

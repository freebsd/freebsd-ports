# New ports collection makefile for:	py-pillow
# Date created:		2012-05-28
# Whom:			koobs <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pillow
PORTVERSION=	1.7.7
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYDISTUTILS_PKGNAME}-${PORTVERSION}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Fork of the Python Imaging Library (PIL)

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		freetype:${PORTSDIR}/print/freetype2

CONFLICTS_INSTALL=	py*-imaging-*

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PYDISTUTILS_PKGNAME=	Pillow
PYEASYINSTALL_ARCHDEP=	yes

.include <bsd.port.mk>

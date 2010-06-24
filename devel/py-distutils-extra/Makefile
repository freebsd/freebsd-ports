# New ports collection makefile for:	py-distutils-extra
# Date created:				07 Mar 2010
# Whom:					Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=		distutils-extra
PORTVERSION=		2.19
CATEGORIES=		devel python
MASTER_SITES=		http://launchpadlibrarian.net/48109785/
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		dist-python-${PORTNAME}-${PORTVERSION}

MAINTAINER=		jupengfei@gmail.com
COMMENT=		Add support for i18n, documentation and icons to distutils

WRKSRC=			${WRKDIR}/python-${PORTNAME}-${PORTVERSION}
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	python_distutils_extra
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.mk>

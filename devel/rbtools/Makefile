# Created by: Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	${ORIGNAME:L}
DISTVERSION=	0.4.2
CATEGORIES=	devel
MASTER_SITES=	http://downloads.reviewboard.org/releases/${ORIGNAME}/${DISTVERSION:C|^(...).*|\1|}/
DISTNAME=	${ORIGNAME}-${DISTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	ReviewBoard Toolset

LICENSE=	MIT

ORIGNAME=	RBTools

USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	${ORIGNAME}
PYDISTUTILS_PKGVERSION=	${DISTVERSION}

PLIST_FILES=	bin/post-review \
		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>

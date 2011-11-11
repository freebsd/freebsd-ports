# New ports collection makefile for:	rbtools
# Date created:				Jul 15 2009
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${ORIGNAME:L}
DISTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://downloads.reviewboard.org/releases/${ORIGNAME}/${DISTVERSION:C|^(...).*|\1|}/
DISTNAME=	${ORIGNAME}-${DISTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	ReviewBoard Toolset

ORIGNAME=	RBTools

USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	${ORIGNAME}
PYDISTUTILS_PKGVERSION=	${DISTVERSION}

PLIST_FILES=	bin/post-review \
		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>

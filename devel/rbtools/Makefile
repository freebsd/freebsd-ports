# New ports collection makefile for:	rbtools
# Date created:				Jul 15 2009
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${ORIGNAME:L}
DISTVERSION=	0.2beta1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://downloads.review-board.org/releases/${ORIGNAME}/${DISTVERSION:C/[a-z].*//}/
DISTNAME=	${ORIGNAME}-${DISTVERSION}
ORIGNAME=	RBTools

MAINTAINER=	flz@FreeBSD.org
COMMENT=	ReviewBoard Toolset

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=1.4:${PORTSDIR}/devel/py-simplejson

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	${ORIGNAME}
PYDISTUTILS_PKGVERSION=	${DISTVERSION}

.include <bsd.port.mk>

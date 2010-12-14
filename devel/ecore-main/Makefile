# New ports collection makefile for:	ecore-main
# Date created:				17 September 2007
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	main
DISTVERSION=	1.0.0.beta
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2010-10-03/base/
PKGNAMEPREFIX=	ecore-
DISTNAME=	ecore-${DISTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (main library)

LICENSE=	BSD
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eina libtool_hack
USE_GETTEXT=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_ICONV=	yes
USE_LDCONFIG=	yes

.include "Makefile.inc"

.include <bsd.port.mk>

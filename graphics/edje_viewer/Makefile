# New ports collection makefile for:	edje_viewer
# Date created:		2006-08-14
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	edje_viewer
PORTVERSION=	20101003
PORTREVISION=	1
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://files.roorback.net/e17/2010-10-03/extra/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A simple viewer for .edj files

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	evas ecore edje elementary
USE_EFL_ECORE=	file
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>

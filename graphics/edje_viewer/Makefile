# New ports collection makefile for:	edje_viewer
# Date created:		2006-08-14
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	edje_viewer
PORTVERSION=	20060926
CATEGORIES=	graphics
MASTER_SITES=	http://sunner.elcomnet.ru/~stas/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A simple viewer for .edj files

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	evas ecore edje etk
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>
.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>

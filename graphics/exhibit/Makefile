# New ports collection makefile for:	exhibit
# Date created:		2006-08-15
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	exhibit
PORTVERSION=	20080223
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An ETK-based image viewer

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	evas eet ecore edje etk epsilon efreet
USE_EFL_ECORE=	evas file
WANT_EFL=	yes
GNU_CONFIGURE=	yes

OPTIONS=	ENGRAVE "Enable E17 desktop wallpaper support" on \
		ENLIGHTENMENT "Enable e17 desktop integration" off

PLIST_FILES=	bin/exhibit %%DATADIR%%/gui.edj
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ENGRAVE) || ${HAVE_EFL:Mengrave}
USE_EFL+=	engrave
.endif

.if defined(WITH_ENLIGHTENMENT) || exists(${LOCALBASE}/bin/enlightenment_remote)
BUILD_DEPENDS+=	enlightenment_remote:${PORTSDIR}/x11-wm/enlightenment
RUN_DEPENDS+=	enlightenment_remote:${PORTSDIR}/x11-wm/enlightenment
.endif

.include <bsd.port.post.mk>

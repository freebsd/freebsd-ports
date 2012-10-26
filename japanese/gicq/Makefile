# Created by: Seiichirou Hiraoka
# $FreeBSD$

PORTNAME=	gicq
PORTVERSION=	0.33
PORTREVISION=	5
CATEGORIES=	japanese net
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.korsoft.com/pub/gicq/
MASTER_SITE_SUBDIR=	flathill

DEPRECATED=	No more public distfiles and development ceased
EXPIRATION_DATE=	2012-11-26

PATCH_SITES=	http://download.sourceforge.net/gicq/ \
		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	flathill
PATCHFILES=	${DISTNAME}ja.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK based ICQ program

LIB_DEPENDS=	icq.0:${PORTSDIR}/japanese/libicq

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnome --disable-nls
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>

# New ports collection makefile for:	devhelp
# Date created:				29 May 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	devhelp
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES?=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C,^([[:digit:]]+\.[[:digit:]]+).*,\1,}
DIST_SUBDIR=	gnome2

MAINTAINER=	rui@ruilopes.com
COMMENT=	Developer help browser for GNOME 2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix libgtkhtml libgnomeui
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"

.include <bsd.port.mk>

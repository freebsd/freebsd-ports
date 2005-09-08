# New ports collection makefile for:	nautilus-actions
# Date created:		2005-08-31
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nautilus-actions
PORTVERSION=	0.6
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~ahze/distfiles/
MASTER_SITE_SUBDIR=	ahze

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Extension for Nautilus to configure programs to launch on files

USE_GNOME=	nautilus2 pygtk2 intlhack
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_PYTHON=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INTLTOOLIZE?=	${LOCALBASE}/bin/intltoolize

pre-configure:
	cd ${WRKSRC} && ${INTLTOOLIZE} --force

.include <bsd.port.mk>

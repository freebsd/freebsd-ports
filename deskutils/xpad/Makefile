# New ports collection makefile for:	xpad
# Date created:		6 March 2002
# Whom:			Guillaume Paquet <amyfoub@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xpad
PORTVERSION=	2.11
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	amyfoub@gmail.com
COMMENT=	A virtual note-pad system for your X11 desktop

USE_BZIP2=	yes
USE_GNOME=	pkgconfig gtk20 gnomehack intltool
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		xpad.1

.include <bsd.port.mk>

# New ports collection makefile for:	glunarclock
# Date created:		9 December 2003
# Whom:			Vincent Tantardini <vinc@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	glunarclock
PORTVERSION=	0.30.3
PORTREVISION=	5
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME applet that displays the current phase of the Moon

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomepanel gail gnomehack gnomeprefix
USE_LIBTOOL_VER=	13
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>

# New ports collection makefile for:	VisualOS
# Date created:				26 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	VisualOS
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	emulators gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A visual simulator of an operating system to help understand how OSes work

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix libglade
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		VisualOS.1

.include <bsd.port.mk>

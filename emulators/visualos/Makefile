# New ports collection makefile for:	VisualOS
# Date created:				26 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	VisualOS
PORTVERSION=	1.0.5
PORTREVISION=	6
CATEGORIES=	emulators gnome
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A visual simulator of an operating system to help understand how OSes work

USE_GNOME=	gnomehack gnomeprefix libglade
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		VisualOS.1

post-patch:
	@${REINPLACE_CMD} -e '/^#define _/d' ${WRKSRC}/src/signals.c

.include <bsd.port.mk>

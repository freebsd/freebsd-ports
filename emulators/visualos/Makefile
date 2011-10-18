# New ports collection makefile for:	VisualOS
# Date created:				26 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	VisualOS
PORTVERSION=	1.0.5
PORTREVISION=	8
CATEGORIES=	emulators gnome
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visual simulator of an operating system to help understand an OSes

LICENSE=	GPLv2

USE_GNOME=	gnomehack gnomeprefix libglade
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		VisualOS.1

post-patch:
	@${REINPLACE_CMD} -e '/^#define _/d' ${WRKSRC}/src/signals.c

.include <bsd.port.mk>

# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	VisualOS
PORTVERSION=	1.0.5
PORTREVISION=	9
CATEGORIES=	emulators gnome
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visual simulator of an operating system to help understand an OSes

LICENSE=	GPLv2

USES=        pathfix
USE_GNOME=	gnomeprefix libglade
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		VisualOS.1

post-patch:
	@${REINPLACE_CMD} -e '/^#define _/d' ${WRKSRC}/src/signals.c

.include <bsd.port.mk>

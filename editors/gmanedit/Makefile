# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmanedit
PORTVERSION=	0.4.2
PORTREVISION=	7
CATEGORIES=	editors gnome
MASTER_SITES=	SF/${PORTNAME}2/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME manpages editor

USES=		gettext gmake gnome pathfix pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lz

post-patch:
	@${REINPLACE_CMD} -e '/<argz\.h>/d' ${WRKSRC}/src/callbacks.c

.include <bsd.port.mk>

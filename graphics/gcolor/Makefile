# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	gcolor
PORTVERSION=	0.4
PORTREVISION=	7
CATEGORIES=	graphics x11
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-based color picker

PLIST_FILES=	bin/gcolor
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

pre-patch:
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>

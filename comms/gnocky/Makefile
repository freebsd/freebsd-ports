# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnocky
PORTVERSION=	0.0.7
PORTREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	http://www.gnokii.org/download/gnocky/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical (GTK+2) frontend for gnokii

LIB_DEPENDS=	libgnokii.so:comms/gnokii

USES=		gnome pkgconfig tar:bzip2
USE_GNOME=	gtk20 libglade2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS

OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>

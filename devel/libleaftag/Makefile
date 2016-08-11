# Created by: Khairil Yusof <kaeru@inigo-tech.com>
# $FreeBSD$

PORTNAME=	libleaftag
PORTVERSION=	0.3.1
PORTREVISION=	3
CATEGORIES=	devel deskutils
MASTER_SITES=	http://releases.chipx86.com/leaftag/libleaftag/

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	Leaftag is a library for tagging files on the desktop

USES=		gmake pathfix pkgconfig libtool sqlite:2
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>

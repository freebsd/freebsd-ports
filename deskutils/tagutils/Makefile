# Created by: Khairil Yusof <kaeru@inigo-tech.com>
# $FreeBSD$

PORTNAME=	tagutils
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://releases.chipx86.com/leaftag/tagutils/

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	Command line tool for tagging files

LIB_DEPENDS=	libleaftag.so:devel/libleaftag

GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>

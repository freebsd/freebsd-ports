# New ports collection makefile for:    tagutils
# Date Created:             24 May 2006
# Whom:                Khairil Yusof <kaeru@inigo-tech.com>
#
# $FreeBSD$
#

PORTNAME=	tagutils
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://releases.chipx86.com/leaftag/tagutils/

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	A command line tool for tagging files

LIB_DEPENDS=	leaftag.0:${PORTSDIR}/devel/libleaftag

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack glib20 pkgconfig
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>

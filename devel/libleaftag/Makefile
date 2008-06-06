# New ports collection makefile for:    libleaftag
# Date Created:             24 May 2006
# Whom:                Khairil Yusof <kaeru@inigo-tech.com>
#
# $FreeBSD$
#

PORTNAME=	libleaftag
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	devel deskutils
MASTER_SITES=	http://releases.chipx86.com/leaftag/libleaftag/

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	Leaftag is a library for tagging files on the desktop

USE_SQLITE=	2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack glib20 pkgconfig
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>

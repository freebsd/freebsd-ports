# New ports collection makefile for:	freeciv
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $FreeBSD$
#

PORTNAME=	freeciv
PORTVERSION=	1.12.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.freeciv.org/pub/freeciv/stable/ \
		ftp://ftp.netc.pt/pub/freeciv/stable/ \
		ftp://ftp.pvv.ntnu.no/pub/freeciv/stable/

MAINTAINER=	sheldonh@freebsd.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_XPM=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(WITH_GTK)
USE_IMLIB=	yes
.else
CONFIGURE_ARGS=	--disable-gtktest
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	genius
# Date created:				1 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	genius
PORTVERSION=	0.5.6
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://ftp.5z.com/pub/genius/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Arbitrary precision calculator for Gnome Desktop Environment

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

USE_PERL5_BUILD=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gtksourceview libgnomeui vte
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500018
BROKEN=		"Requires readline 4.2 or newer"
.endif

.include <bsd.port.post.mk>

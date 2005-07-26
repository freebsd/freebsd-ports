# New ports collection makefile for:	genius
# Date created:				1 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	genius
PORTVERSION=	0.7.4
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME} \
		http://ftp.5z.com/pub/genius/
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Arbitrary precision calculator for Gnome Desktop Environment

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gtksourceview intlhack \
		libgnomeui vte
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
LIBTOOLFILES=	configure mpfr/configure
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-extra-gcc-optimization
INSTALLS_OMF=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500018
BROKEN=		Does not compile on 4.x
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
.endif

.include <bsd.port.post.mk>

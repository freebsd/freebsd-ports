# New ports collection makefile for:	gqmpeg
# Date Created:		28 Oct 1998
# Whom:			Vanilla Pooh Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gqmpeg
PORTVERSION=	0.11.0
CATEGORIES+=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER?=	lyngbol@wheel.dk

LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

USE_X_PREFIX=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
WANT_GNOME=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		USE_GNOME="${USE_GNOME}"

MAN1=		gqmpeg.1

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
.endif

post-patch:
	@find ${WRKSRC} -name 'Makefile.in*' | xargs ${PERL} -pi.orig -e \
		's|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.post.mk>

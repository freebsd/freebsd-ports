# New ports collection makefile for:	gdcd
# Date created:				Sat 3 June 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	gdcd
PORTVERSION=	0.2.1
CATEGORIES=	audio
MASTER_SITES=	http://cdcd.undergrid.net/gdcd/source_archive/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	cdaudio.1:${PORTSDIR}/audio/libcdaudio

USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_AUTOMAKE=	yes
AUTOMAKE=	automake -a -i
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-configure:
	@cd ${WRKSRC}; aclocal -I ${X11BASE}/share/aclocal

.include <bsd.port.mk>

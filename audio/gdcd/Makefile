# New ports collection makefile for:	gdcd
# Date created:				Sat 3 June 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	gdcd
PORTVERSION=	0.2.1
CATEGORIES=	audio
MASTER_SITES=	http://gdcd.undergrid.net/source_archive/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	CD player for the X Window System using the GIMP Tool Kit (GTK)

BROKEN=		"Does not build"

LIB_DEPENDS=	cdaudio.1:${PORTSDIR}/audio/libcdaudio

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomelibs gdkpixbuf
USE_AUTOMAKE_VER=	15
AUTOMAKE_ARGS=	-a -i
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-configure:
	@cd ${WRKSRC}; ${ACLOCAL} -I ${X11BASE}/share/aclocal

pre-build:
	@${REINPLACE_CMD} -e "s/autoheader/${AUTOHEADER}/" \
		${BUILD_WRKSRC}/Makefile

.include <bsd.port.mk>

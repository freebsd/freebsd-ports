# New ports collection makefile for:	anjuta
# Date created:				31 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	anjuta
PORTVERSION=	1.0.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	anjuta

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	scintilla.1:${PORTSDIR}/x11-toolkits/scintilla

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomevfs gnomeprint gdkpixbuf
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's#-lpthread#${PTHREAD_LIBS}#g ; \
		 s#DATADIRNAME=lib#DATADIRNAME=share#g' ${WRKSRC}/configure

.include <bsd.port.mk>

# New ports collection makefile for:	anjuta
# Date created:				31 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	anjuta
PORTVERSION=	0.1.9
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	anjuta

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	scintilla.1:${PORTSDIR}/x11-toolkits/scintilla
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's#-lpthread#${PTHREAD_LIBS}#g ; \
		 s#DATADIRNAME=lib#DATADIRNAME=share#g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's#\$\(datadir\)/gnome/#\$\(datadir\)/#g ; \
		 s#\$\(datadir\)/locale#\$\(prefix\)/share/locale#g'

.include <bsd.port.mk>

# New ports collection makefile for:	MrProject
# Date created:				15 July 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mrproject
PORTVERSION=	0.3.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	anjuta

MAINTAINER=	demon@FreeBSD.org

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

pre-patch:
	@${PERL} -pi -e 's#-lpthread#-pthread#g ; \
		s#DATADIRNAME=lib#DATADIRNAME=share#g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		 's#\$\(datadir\)/locale#\$\(prefix\)/share/locale#g'

.include <bsd.port.mk>

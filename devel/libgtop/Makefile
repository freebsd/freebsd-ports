# New ports collection makefile for:	libgtop
# Date Created:			26 Sep 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgtop
PORTVERSION=	1.0.11
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/libgtop

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	guile.9:${PORTSDIR}/lang/guile

USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOMELIBS=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-install:
	install-info --section="Programming \& development tools" \
	--entry="* libgtop: (libgtop).	libgtop programming manual" \
	${PREFIX}/info/libgtop.info ${PREFIX}/info/dir

.include <bsd.port.mk>

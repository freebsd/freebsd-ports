# New ports collection makefile for:	libgtop
# Date Created:			26 Sep 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgtop
PORTVERSION=	1.0.13
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/libgtop/1.0

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	guile.10:${PORTSDIR}/lang/guile

USE_PERL5=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomelibs
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

post-install:
	install-info --section="Programming \& development tools" \
	--entry="* libgtop: (libgtop).	libgtop programming manual" \
	${PREFIX}/info/libgtop.info ${PREFIX}/info/dir

.include <bsd.port.mk>

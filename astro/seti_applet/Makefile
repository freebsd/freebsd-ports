# New ports collection makefile for:	seti_applet
# Date Created:		1 Jul 2000
# Whom:			HIYAMA Takeshi <th@cis.ibaraki.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	seti_applet
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	astro gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_/-/}

MAINTAINER=	cbc06942@pop06.odn.ne.jp

LIB_DEPENDS=	gtop.1:${PORTSDIR}/devel/libgtop
RUN_DEPENDS=	setiathome:${PORTSDIR}/astro/setiathome

USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-install:
	${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g" ${PKGMESSAGE}

.include <bsd.port.mk>

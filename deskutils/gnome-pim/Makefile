# New ports collection makefile for:	gnomepim
# Date created:				17 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomepim
PORTVERSION=	1.4.3
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.eskil.org/gnome-pilot/download/tarballs/ \
		${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-pim
DISTNAME=	gnome-pim-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

.if defined(WITHOUT_PILOT)
BUILD_DEPENDS=	${X11BASE}/lib/gnome-pilot/conduits/libemail_conduit.so:${PORTSDIR}/palm/gnomepilot-conduits
RUN_DEPENDS=	${X11BASE}/lib/gnome-pilot/conduits/libemail_conduit.so:${PORTSDIR}/palm/gnomepilot-conduits
.endif

USE_X_PREFIX=	yes
USE_BISON=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LIBS=		-L${LOCALBASE}/lib
.if defined(WITHOUT_PILOT)
CONFIGURE_ARGS=	--without-pisock --disable-pilotlinktest
.else
CONFIGURE_ARGS=	--with-pisock=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
.endif
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LIBS="${LIBS}"

pre-extract:
	@${ECHO_MSG}
.if defined(WITHOUT_PILOT)
	@${ECHO_MSG} "Palm Pilot support disabled. You will not be able to syncronize"
	@${ECHO_MSG} "your palm with gnomecard and gnomecal."
.else
	@${ECHO_MSG} "You can disable Palm Pilot support by defining WITHOUT_PILOT."
.endif
	@${ECHO_MSG}

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'
.for file in vcc.y vobject.c
	@${PERL} -pi -e "s/malloc.h/stdlib.h/g" ${WRKSRC}/libversit/${file}
.endfor

.include <bsd.port.mk>

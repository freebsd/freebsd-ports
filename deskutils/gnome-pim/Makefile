# New ports collection makefile for:	gnomepim
# Date created:				17 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomepim
PORTVERSION=	1.2.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-pim
DISTNAME=	gnome-pim-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

.if defined(WITH_GNOMEPILOT)
LIB_DEPENDS+=	gpilotd.0:${PORTSDIR}/palm/gnomepilot
PILOTINC=	"-I${LOCALBASE}/pilot/include"
PILOTLIB=	"-L${LOCALBASE}/pilot/lib"
PLIST_SUB+=	GNOMEPILOT:=""
.else
CONFIGURE_ARGS=	--without-pisock --disable-pilotlinktest
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-nopilot
PLIST_SUB+=	GNOMEPILOT:="@comment "
.endif

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PILOTINC}" \
		LIBS="-L${LOCALBASE}/lib ${PILOTLIB}"

.if !defined(WITH_GNOMEPILOT)
pre-extract:
	@${ECHO} "You can add gnomepilot support by defining WITH_GNOMEPILOT"
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>

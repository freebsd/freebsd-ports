# New ports collection makefile for:	gnomepim
# Date created:				17 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomepim
PORTVERSION=	1.4.9
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://me.in-berlin.de/~jroger/gnome-pim/ \
		${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-pim/1.4
DISTNAME=	gnome-pim-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org

.if !defined(WITHOUT_PILOT)
BUILD_DEPENDS=	${X11BASE}/lib/gnome-pilot/conduits/libemail_conduit.so:${PORTSDIR}/palm/gnomepilot-conduits
RUN_DEPENDS=	${X11BASE}/lib/gnome-pilot/conduits/libemail_conduit.so:${PORTSDIR}/palm/gnomepilot-conduits
PLIST_SUB=	GNOME_PILOT=""
.else
PLIST_SUB=	GNOME_PILOT="@comment "
.endif

USE_X_PREFIX=	yes
USE_BISON=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs libcapplet
USE_LIBTOOL=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LIBS=		-L${LOCALBASE}/lib
.if !defined(WITHOUT_PILOT)
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

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
.for file in vcc.y vobject.c
	@${REINPLACE_CMD} -e "s/malloc[.]h/stdlib.h/g" ${WRKSRC}/libversit/${file}
.endfor

pre-install:
	${MKDIR} ${PREFIX}/share/gnome/help/gnomecard/C \
		${PREFIX}/share/gnome/help/gnomecard/eu

.include <bsd.port.mk>

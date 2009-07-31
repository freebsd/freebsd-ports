# New ports collection makefile for:	gspeakers
# Date created:				10th December 2003
# Whom:					Vincent Tantardini <vinc@freebsd-fr.org>
#
# $FreeBSD$
#    $MCom: ports/audio/gspeakers/Makefile,v 1.6 2007/05/30 17:08:11 mezz Exp $

PORTNAME=	gspeakers
PORTVERSION=	0.11
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome-based loudspeaker design program

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_GNOME=	gnomeprefix gnometarget libxml2
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:19:env
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CFLAGS+=	-O0

.if defined(WITH_SPICE)
RUN_DEPENDS+=	spice3:${PORTSDIR}/cad/spice
.else
RUN_DEPENDS+=	gnucap:${PORTSDIR}/cad/gnucap
.endif

post-extract:
	@${FIND} ${WRKSRC} -type l -delete

post-patch:
	@${REINPLACE_CMD} -e 's|$$(datadir)/pixmaps|$$(pkgdatadir)/pixmaps|g' \
		${WRKSRC}/pixmaps/Makefile.in
	@${REINPLACE_CMD} -e 's|-Wall -O0|@CXXFLAGS@|g' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(datadir)/xml|$$(pkgdatadir)/xml|g' \
		${WRKSRC}/xml/Makefile.in

pre-configure:
	@${CP} ${AUTOMAKE_DIR}/depcomp ${WRKSRC}

.include <bsd.port.mk>

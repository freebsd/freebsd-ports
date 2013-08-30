# Created by: Vincent Tantardini <vinc@freebsd-fr.org>
# $FreeBSD$
#    $MCom: ports/audio/gspeakers/Makefile,v 1.6 2007/05/30 17:08:11 mezz Exp $

PORTNAME=	gspeakers
PORTVERSION=	0.11
PORTREVISION=	13
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome-based loudspeaker design program

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USES=		gmake
USE_GNOME=	gnomeprefix libxml2
USE_AUTOTOOLS=	automake:env
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/*.cc ${WRKSRC}/src/cellitemcrossover.h

pre-configure:
	@${CP} ${AUTOMAKE_DIR}/depcomp ${WRKSRC}

.include <bsd.port.mk>

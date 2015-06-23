# Created by: Vincent Tantardini <vinc@freebsd-fr.org>
# $FreeBSD$
#    $MCom: ports/audio/gspeakers/Makefile,v 1.6 2007/05/30 17:08:11 mezz Exp $

PORTNAME=	gspeakers
PORTVERSION=	0.11
PORTREVISION=	16
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome-based loudspeaker design program

LIB_DEPENDS=	libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24

USES=		autoreconf gmake pkgconfig
USE_GNOME=	gnomeprefix libxml2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CFLAGS+=	-O0

OPTIONS_DEFINE=	SPICE
SPICE_DESC=	Use spice instead of gnucap

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSPICE}
RUN_DEPENDS+=	spice3:${PORTSDIR}/cad/spice
.else
RUN_DEPENDS+=	gnucap:${PORTSDIR}/cad/gnucap
.endif

post-extract:
	@${FIND} ${WRKSRC} -type l -delete

post-patch:
	@${REINPLACE_CMD} -e 's|$$(datadir)/pixmaps|$$(pkgdatadir)/pixmaps|g' \
		${WRKSRC}/pixmaps/Makefile.am
	@${REINPLACE_CMD} -e 's|-Wall -O0|@CXXFLAGS@|g' \
		${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e 's|$$(datadir)/xml|$$(pkgdatadir)/xml|g' \
		${WRKSRC}/xml/Makefile.am
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/*.cc ${WRKSRC}/src/cellitemcrossover.h

.include <bsd.port.mk>

# New ports collection makefile for:	gspeakers
# Date created:				10th December 2003
# Whom:					Vincent Tantardini <vinc@freebsd-fr.org>
#
# $FreeBSD$

PORTNAME=	gspeakers
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome-based loudspeaker design program

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_X_PREFIX=	yes
USE_GCC=	3.4
USE_GNOME=	gnomeprefix gnometarget libxml2
USE_REINPLACE=	yes
USE_GMAKE=	yes
WANT_AUTOMAKE_VER=	19
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
	@${REINPLACE_CMD} -e 's|/gnome/apps/|/apps/|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(datadir)/pixmaps|$$(pkgdatadir)/pixmaps|g' \
		${WRKSRC}/pixmaps/Makefile.in
	@${REINPLACE_CMD} -e 's|-Wall -O0|@CXXFLAGS@|g' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(datadir)/xml|$$(pkgdatadir)/xml|g' \
		${WRKSRC}/xml/Makefile.in
	@${FIND} ${WRKSRC} \( -name "*.cc" -or -name "*.xml" \) | \
		${XARGS} ${REINPLACE_CMD} -e \
		's|/share/pixmaps/|/share/gnome/gspeakers/pixmaps/|g ; \
		 s|/share/xml/|/share/gnome/gspeakers/xml/|g'

pre-configure:
	@${CP} ${AUTOMAKE_DIR}/depcomp ${WRKSRC}

.include <bsd.port.mk>

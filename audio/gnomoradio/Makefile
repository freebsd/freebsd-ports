# New ports collection makefile for:	gnomoradio
# Date created:			23 Oct 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		gnomoradio
PORTVERSION=		0.15.1
PORTREVISION=		11
CATEGORIES=		audio net
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		gahr@FreeBSD.org
COMMENT=		A program for finding and playing free music from the Internet

LIB_DEPENDS=		sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
			gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
			gconfmm-2.6:${PORTSDIR}/devel/gconfmm26 \
			xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26 \
			vorbis:${PORTSDIR}/audio/libvorbis \
			ao:${PORTSDIR}/audio/libao

USE_GNOME=		gnomehack gnomeprefix
USE_AUTOTOOLS=		libtool:15
USE_LDCONFIG=		yes
LIBTOOLFLAGS=		--tag=CXX
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|CCLD = $$(CC)|CCLD = $$(CXX)|; \
		s|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/roboradio/mp3/Makefile.in
	@${REINPLACE_CMD} -e 's|static char|static const char|' \
		${WRKSRC}/gnomoradio/*.xpm

.include <bsd.port.mk>

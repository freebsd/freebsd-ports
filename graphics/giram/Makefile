# New ports collection makefile for:	giram
# Date created:        17 June 1999
# Whom:                Brandon Fosdick <bfoz@glue.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	giram
PORTVERSION=	0.1.6
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.giram.org/pub/
DISTNAME=	Giram-${PORTVERSION}

MAINTAINER=	bfoz@glue.umd.edu

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		GL:${PORTSDIR}/graphics/Mesa3
RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray31

GTK_CONFIG?=    ${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS= --disable-gnome

post-install:
	@${MKDIR} ${PREFIX}/share/doc/giram/SampleScenes
	${INSTALL_DATA} ${WRKSRC}/SampleScenes/* ${PREFIX}/share/doc/giram/SampleScenes/

.include <bsd.port.mk>

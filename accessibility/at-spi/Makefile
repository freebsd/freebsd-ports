# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/accessibility/at-spi/Makefile,v 1.103 2010/09/27 09:47:42 kwm Exp $

PORTNAME=	at-spi
PORTVERSION=	1.32.0
PORTREVISION?=	6
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Assistive Technology Service Provider Interface

USES+=		tar:bzip2

.if !defined(REFERENCE_PORT)

RUN_DEPENDS=	at-spi2-atk>2.6.0:accessibility/at-spi2-atk

USES+=		gmake gettext libtool pathfix pkgconfig python:2
USE_GNOME=	intlhack gtk20 gconf2 libbonobo
USE_XORG=	x11 xtst
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	at-spi.schemas

post-extract:
	@${RM} ${WRKSRC}/registryd/Accessibility_Registry.server

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/test//" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/docs//" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/atk-bridge//" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif

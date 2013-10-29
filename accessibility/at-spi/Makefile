# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/accessibility/at-spi/Makefile,v 1.103 2010/09/27 09:47:42 kwm Exp $

PORTNAME=	at-spi
PORTVERSION=	1.32.0
PORTREVISION?=	2
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Assistive Technology Service Provider Interface

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

RUN_DEPENDS=	at-spi2-atk>2.6.0:${PORTSDIR}/accessibility/at-spi2-atk

NO_STAGE=	yes
USES=		gmake gettext pkgconfig
USE_GNOME=	gnomehack gnomehier intlhack gtk20 gconf2 libbonobo
USE_XORG=	x11 xtst
USE_PYTHON=	-2.7
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	at-spi.schemas

post-extract:
	@${RM} -f ${WRKSRC}/registryd/Accessibility_Registry.server

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/test//" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/docs//" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/atk-bridge//" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif

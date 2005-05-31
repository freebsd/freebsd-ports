# ex:ts=8
# Ports collection makefile for:	eboxy
# Date created:			Sep 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	eboxy
PORTVERSION=	0.4.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create simple GUI interfaces for entertainment PC

USE_BISON=	yes
USE_BZIP2=	yes
USE_SDL=	sdl gui mixer
USE_GNOME=	gnometarget libxml2 lthack
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-lirc

MAN1=		eboxy.1

CPPFLAGS=	`${SDL_CONFIG} --cflags` -I${LOCALBASE}/include \
		-DHAVE_DECL_GETOPT -fPIC
LDFLAGS=	`${SDL_CONFIG} --libs` -L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		"Configure fails on ia64"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 $$CFLAGS|$$CFLAGS|g ; \
		 s|-O2 $$CXXFLAGS|$$CXXFLAGS|g' ${WRKSRC}/configure

pre-build:
	@cd ${WRKSRC}/eboxy && ${SH} ./makeparser.sh

.include <bsd.port.post.mk>

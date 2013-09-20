# Created by: ijliao
# $FreeBSD$
#    $MCom: ports/devel/liboil/Makefile,v 1.7 2008/03/23 06:57:57 marcus Exp $

PORTNAME=	liboil
PORTVERSION=	0.3.17
CATEGORIES=	devel
MASTER_SITES=	http://liboil.freedesktop.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of optimized inner loops

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pathfix pkgconfig
USE_GNOME=	ltverhack
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--disable-glib
CFLAGS:=	${CFLAGS:N-O*} -O2

_COMPILER_VERSION!=	${CC} --version
.if ${_COMPILER_VERSION:Mclang}
CFLAGS+=	-fheinous-gnu-extensions
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|\\$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|<stdint\.h|<inttypes.h|g' \
		${WRKSRC}/liboil/liboiltypes.h \
		${WRKSRC}/liboil/liboilprofile.h \
		${WRKSRC}/liboil/liboil.h

.include <bsd.port.post.mk>

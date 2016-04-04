# Created by: Jim Pirzyk <pirzyk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	epkg
PORTVERSION=	2.3.9
PORTREVISION=	6
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.feep.net/pub/encap/epkg/

MAINTAINER=	pirzyk@FreeBSD.org
COMMENT=	Encap Package Manager

BROKEN=		unfetchable

BUILD_DEPENDS=	${LOCALBASE}/lib/libfget.a:ftp/fget
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2

HAS_CONFIGURE=	YES
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-encap --disable-epkg-install --without-libtar \
		--with-libfget \
		--prefix=${PREFIX}
INSTALL_TARGET=	install-recurse

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	@${CP} ${WRKSRC}/mkencap/mkencap_environment ${STAGEDIR}${PREFIX}/etc/mkencap_environment.sample

.include <bsd.port.mk>

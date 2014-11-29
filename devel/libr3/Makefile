# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	libr3
PORTVERSION=	1.0.0
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	URL router library with high performance

LICENSE=	MIT

LIB_DEPENDS=	libcheck.so:${PORTSDIR}/devel/libcheck \
		libgvc.so:${PORTSDIR}/graphics/graphviz \
		libpcre.so:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-graphviz
USES=		libtool pkgconfig
INSTALL_TARGET=	install-strip
USE_AUTOTOOLS=  aclocal:env autoconf:env autoheader:env automake:env libtoolize:env

USE_GITHUB=	yes
GH_ACCOUNT=	c9s
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	ad8faeb
GH_PROJECT=	r3

post-patch:
	@${REINPLACE_CMD} 's,^pkgconfigdir = .*,pkgconfigdir=$${prefix}/libdata/pkgconfig,' \
		${WRKSRC}/Makefile.am

pre-configure:
	(cd ${WRKSRC} && ./autogen.sh)

.include <bsd.port.mk>

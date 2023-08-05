PORTNAME=	regexx
PORTVERSION=	0.98.1
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete regular expressions C++ solution
WWW=		https://sourceforge.net/projects/regexx/

LICENSE=	LGPL21

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		gmake pkgconfig libtool
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

CPPFLAGS+=	$$(pkg-config --cflags libpcre)
LDFLAGS+=	$$(pkg-config --libs libpcre)

post-patch:
	@${REINPLACE_CMD} -e \
		's|"pcre"||' ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libregexx.so

.include <bsd.port.mk>

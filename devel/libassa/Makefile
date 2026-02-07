PORTNAME=	libassa
DISTVERSION=	3.5.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION:C/\.[0-9]*$//}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	C++ networking library and application framework
WWW=		https://libassa.sourceforge.net/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix pkgconfig
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	TIRPC_CFLAGS=" " TIRPC_LIBS=" "

PLIST_SUB=	ASSA_VERSION=${PORTVERSION:R:R}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/-.*$//}

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s: doc : :g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/debian/assa-genesis.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

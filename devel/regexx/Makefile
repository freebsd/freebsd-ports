# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	regexx
PORTVERSION=	0.98.1
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete regular expressions C++ solution

LICENSE=	LGPL21

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		gmake pkgconfig
USE_AUTOTOOLS=	libtool
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"
USE_LDCONFIG=	yes

CPPFLAGS+=	$$(pkg-config --cflags libpcre)
LDFLAGS+=	$$(pkg-config --libs libpcre)

post-patch:
	@${REINPLACE_CMD} -e \
		's|"pcre"||' ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libregexx.so.2

.include <bsd.port.mk>

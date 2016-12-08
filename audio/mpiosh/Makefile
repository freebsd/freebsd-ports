# Created by: Sergey Akifyev <asa@gascom.ru>
# $FreeBSD$

PORTNAME=	mpiosh
PORTVERSION=	0.7.1.p2
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/mpio/mpio%20pre-release/0.7.1-pre2
DISTNAME=	mpio-${PORTVERSION:S|.p|_pre|}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Digit@lway MPIO MP3 player tool

USES=		autoreconf iconv libtool readline
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure.in

post-patch:
	@${REINPLACE_CMD} -e 's/%%ICONV_LIB%%/${ICONV_LIB}/' ${WRKSRC}/mpiosh/Makefile.am

.include <bsd.port.mk>

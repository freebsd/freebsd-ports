# Created by: Sergey Akifyev <asa@gascom.ru>

PORTNAME=	mpiosh
PORTVERSION=	0.7.1.p2
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF/mpio/mpio%20pre-release/0.7.1-pre2
DISTNAME=	mpio-${PORTVERSION:S|.p|_pre|}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Digit@lway MPIO MP3 player tool

DEPRECATED=	Abandoned upstream, no new release since 2004
EXPIRATION_DATE=2021-12-31

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

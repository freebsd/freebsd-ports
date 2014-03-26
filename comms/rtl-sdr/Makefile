# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	rtl-sdr
PORTVERSION=	20140210
CATEGORIES=	comms hamradio
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Commandline tool that performs SDR with RTL2832-based USB sticks

LICENSE=	GPLv2

USES=		gmake pkgconfig
USE_AUTOTOOLS=	autoconf:env aclocal:env automake:env libtool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/librtlsdr

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Makefile.am
.endif

post-patch:
	@${REINPLACE_CMD} 's|^pkgdocdir=.*|pkgdocdir=${DOCSDIR}|' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} 's|^pkgconfigdir =.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.am

pre-configure:
	@(cd ${WRKSRC} && ${AUTORECONF} -fi)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librtlsdr.so.0

.include <bsd.port.post.mk>

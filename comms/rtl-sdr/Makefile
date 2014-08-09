# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	rtl-sdr
PORTVERSION=	20140210
PORTREVISION=	3
CATEGORIES=	comms hamradio
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Commandline tool that performs SDR with RTL2832-based USB sticks

LICENSE=	GPLv2

USES=		gmake pkgconfig libtool tar:tgz
USE_AUTOTOOLS=	autoconf:env aclocal:env automake:env libtoolize:env
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/librtlsdr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

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

.include <bsd.port.mk>

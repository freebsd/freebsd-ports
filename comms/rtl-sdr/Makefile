PORTNAME=	rtl-sdr
PORTVERSION=	0.6.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	comms hamradio

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Command-line tool that performs SDR with RTL2832-based USB sticks

LICENSE=	GPLv2

USES=		autoreconf pkgconfig libtool pathfix tar:tgz

USE_GITHUB=	yes
GH_ACCOUNT=	steve-m
GH_PROJECT=	librtlsdr

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/librtlsdr

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-Makefile.am

post-patch:
	@${REINPLACE_CMD} 's|^pkgdocdir=.*|pkgdocdir=${DOCSDIR}|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>

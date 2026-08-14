PORTNAME=	rtl-sdr
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.3
PORTEPOCH=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	https://downloads.osmocom.org/releases/rtl-sdr/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Command-line tool that performs SDR with RTL2832-based USB sticks
WWW=		https://osmocom.org/projects/rtl-sdr/wiki/ \
		https://gitea.osmocom.org/sdr/rtl-sdr/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf pkgconfig libtool localbase tar:bz2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/librtlsdr

WRKSRC=		${WRKDIR}/librtlsdr-${DISTVERSION}

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-Makefile.am

post-patch:
	@${REINPLACE_CMD} 's|^pkgdocdir=.*|pkgdocdir=${DOCSDIR}|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>

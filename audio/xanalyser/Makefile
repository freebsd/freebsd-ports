PORTNAME=	xanalyser
PORTVERSION=	1.32
PORTREVISION=	4
CATEGORIES=	audio hamradio
MASTER_SITES=	http://arvin.schnell-web.net/xanalyser/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Spectrum analyser
WWW=		http://arvin.schnell-web.net/xanalyser/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool motif tar:bzip2 xorg
USE_XORG=	x11 xmu ice sm xt xext
USE_CXXSTD=	c++14 # to fix build on 14 with clang-16 that has c++20 by default: error: ISO C++17 does not allow 'register' storage class specifier

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/xanalyser lib/X11/app-defaults/XAnalyser share/man/man1/xanalyser.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    -e 's|%%MOTIFLIB%%|${MOTIFLIB} |g' \
	    -e 's|%%PREFIX%%|${PREFIX}|g' \
	    ${WRKSRC}/xanalyser.spec.in ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>

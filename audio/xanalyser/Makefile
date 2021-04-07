PORTNAME=	xanalyser
PORTVERSION=	1.32
PORTREVISION=	3
CATEGORIES=	audio hamradio
MASTER_SITES=	http://arvin.schnell-web.net/xanalyser/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Spectrum analyser

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool motif tar:bzip2 xorg
USE_XORG=	x11 xmu ice sm xt xext
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/xanalyser lib/X11/app-defaults/XAnalyser man/man1/xanalyser.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    -e 's|%%MOTIFLIB%%|${MOTIFLIB} |g' \
	    -e 's|%%PREFIX%%|${PREFIX}|g' \
	    ${WRKSRC}/xanalyser.spec.in ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>

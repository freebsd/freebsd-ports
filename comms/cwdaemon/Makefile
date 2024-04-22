PORTNAME=	cwdaemon
PORTVERSION=	0.10.2
PORTREVISION=	1
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio cw (Morse code) keyer daemon

LICENSE=	GPLv2

LIB_DEPENDS=	libcw.so:comms/unixcw

USES=		autoreconf pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	acerion

SHEBANG_FILES=	examples/example.pl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/doc

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/example.sh ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/example.pl ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/example.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

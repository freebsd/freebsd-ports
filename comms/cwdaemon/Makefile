PORTNAME=	cwdaemon
PORTVERSION=	0.10.2
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio cw (Morse code) keyer daemon

LICENSE=	GPLv2

LIB_DEPENDS=	libcw.so:comms/unixcw

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/doc
USES=		pkgconfig autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	acerion

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/example.sh ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/example.pl ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/example.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

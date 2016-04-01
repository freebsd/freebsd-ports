# Created by: Mark Reidel <ports@mark.reidle.info>
# $FreeBSD$

PORTNAME=	musicpc
PORTVERSION=	0.27
CATEGORIES=	audio ipv6
MASTER_SITES=	http://www.musicpd.org/download/mpc/0/
DISTNAME=	mpc-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line client for the musicpd

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient

USES=		pkgconfig tar:xz
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/mpc man/man1/mpc.1.gz

PORTDOCS=	AUTHORS README NEWS
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES DOCS ICONV
OPTIONS_DEFAULT=	ICONV

ICONV_USES=	iconv
ICONV_LDFLAGS=	${ICONV_LIB}
ICONV_CONFIGURE_ENABLE=	iconv

post-patch:
	@${REINPLACE_CMD} -e 's|-lintl|${ICONV_LIB}|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mpc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/mpc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mpc-completion.bash \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

PORTNAME=	dtmfdial
PORTVERSION=	0.2
CATEGORIES=	audio comms
MASTER_SITES=	SUNSITE/apps/sound/misc
DISTNAME=	dtmf-dial-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate DTMF dial tones from the command line

WRKSRC=		${WRKDIR}/dial
MAKE_ARGS=	CFLAGS="${CFLAGS}"
PORTDOCS=	README TODO

PLIST_FILES=	bin/dtmfdial

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dial ${STAGEDIR}${PREFIX}/bin/dtmfdial

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

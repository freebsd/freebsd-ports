PORTNAME=	zorro
PORTVERSION=	1.1.8
PORTREVISION=	3
CATEGORIES=	deskutils tk
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/ \
		ftp://totem.fix.no/pub/mirrors/misc/
DISTNAME=	${PORTNAME}-1.1p8

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple to-do list manager

USES=		tk:run
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	bin/zorro
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/bin/wish|${WISH}|' \
		${WRKSRC}/zorro
	@${REINPLACE_CMD} -e 's|oof|of|' ${WRKSRC}/DOTzorrorc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zorro ${STAGEDIR}${PREFIX}/bin/zorro

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOTzorrorc ${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Take a look at ${STAGEDIR}${DOCSDIR}/DOTzorrorc"
	@${ECHO_MSG} ""

.include <bsd.port.mk>

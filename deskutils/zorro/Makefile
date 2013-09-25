# Created by: shanee@rabbit.augusta.de
# $FreeBSD$

PORTNAME=	zorro
PORTVERSION=	1.1.8
PORTREVISION=	3
CATEGORIES=	deskutils tk
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/ \
		ftp://totem.fix.no/pub/mirrors/misc/
DISTNAME=	${PORTNAME}-1.1p8

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple to-do list manager

USES+=		tk:run
NO_BUILD=	yes
PLIST_FILES=	bin/zorro
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/bin/wish|${WISH}|' \
		${WRKSRC}/zorro
	@${REINPLACE_CMD} -e 's|oof|of|' ${WRKSRC}/DOTzorrorc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zorro ${STAGEDIR}${PREFIX}/bin/zorro

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOTzorrorc ${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Take a look at ${STAGEDIR}${DOCSDIR}/DOTzorrorc"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>

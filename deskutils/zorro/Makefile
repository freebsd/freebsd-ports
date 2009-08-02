# New ports collection makefile for:	zorro
# Date created:         03 Aug 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $FreeBSD$
#

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

USE_TK_RUN=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/zorro
PORTDOCS=	DOTzorrorc

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/bin/wish|${WISH}|' \
		${WRKSRC}/zorro
	@${REINPLACE_CMD} -e 's|oof|of|' ${WRKSRC}/DOTzorrorc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zorro ${PREFIX}/bin/zorro
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOTzorrorc ${DOCSDIR}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Take a look at ${DOCSDIR}/DOTzorrorc"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>

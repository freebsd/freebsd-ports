# Created by: rox@fearme.com
# $FreeBSD$

PORTNAME=	roxirc
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	irc tk
MASTER_SITES=	http://roxirc.lighter.net/download/

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	A tcl/tk irc client

USES+=		tk:run
NO_BUILD=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's|if \[ -x .*|${WISH} "$$0" "$$@"|' ${WRKSRC}/roxirc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/roxirc ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${DOCSDIR}/config-example
	${INSTALL_DATA} ${WRKSRC}/menus ${DOCSDIR}/menus-example
	${INSTALL_DATA} ${WRKSRC}/bindings ${DOCSDIR}/bindings-example
	${INSTALL_DATA} ${WRKSRC}/prefs ${DOCSDIR}/prefs-initial
	${INSTALL_DATA} ${WRKSRC}/startup ${DOCSDIR}/startup-example
	${INSTALL_DATA} ${WRKSRC}/help ${DOCSDIR}/help
.endif

.include <bsd.port.mk>

# Created by: rox@fearme.com
# $FreeBSD$

PORTNAME=	roxirc
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	irc tk
MASTER_SITES=	http://roxirc.lighter.net/download/

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tcl/tk irc client

BROKEN=		unfetchable

USES+=		tk:run
NO_BUILD=	yes

PLIST_FILES=	bin/roxirc
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|if \[ -x .*|${WISH} "$$0" "$$@"|' ${WRKSRC}/roxirc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/roxirc ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in config menus bindings prefs startup help
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/${f}-example
.endfor

.include <bsd.port.mk>

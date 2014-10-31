# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	awale
PORTVERSION=	1.5
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	African board game

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		desktop-file-utils tk

SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS ChangeLog NEWS README THANKS
OPTIONS_DEFINE=	DOCS

post-patch:
	@${ECHO_CMD} "#!/bin/sh" > ${WRKSRC}/src/x${PORTNAME}
	@${ECHO_CMD} "${DATADIR}/xawale.tcl" >> ${WRKSRC}/src/x${PORTNAME}
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh| ; \
		s|exec wish|exec ${WISH}|' \
		${WRKSRC}/src/xawale.tcl
	@${REINPLACE_CMD} -e 's|share/man|man|' \
		${WRKSRC}/man/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

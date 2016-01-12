# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	awale
PORTVERSION=	1.6
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	African board game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tk:wrapper
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

PORTDATA=	*
PORTDOCS=	*
PLIST_FILES=	bin/awale \
		bin/xawale \
		man/man6/awale.6.gz \
		man/man6/xawale.6.gz \
		share/applications/awale.desktop

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/^mandir/s|=.*|= @mandir@|' ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e \
		's|/bin/bash|/bin/sh|' ${WRKSRC}/src/xawale.tcl

post-build:
	@${ECHO_CMD} -n > ${WRKSRC}/src/xawale
	@${ECHO_CMD} "#!/bin/sh" >> ${WRKSRC}/src/xawale
	@${ECHO_CMD} "${DATADIR}/xawale.tcl" >> ${WRKSRC}/src/xawale

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog NEWS README THANKS
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>

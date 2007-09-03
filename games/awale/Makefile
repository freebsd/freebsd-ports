# New ports collection makefile for:	awale
# Date created:		15 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	awale
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	SAVANNAH CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	African board game

USE_TK_RUN=	yes
GNU_CONFIGURE=	yes
PORTDOCS=	AUTHORS ChangeLog NEWS README THANKS
MAN1=	${PORTNAME}.1 x${PORTNAME}.1
PATCH_TK_SCRIPTS=	src/xawale.tcl

pre-patch:
	@${REINPLACE_CMD} -e '/^#define.*VERSION/d' ${WRKSRC}/src/awale.c
	@${REINPLACE_CMD} -e '/^pkgdatadir =/s|=.*|=${DATADIR}|'\
		${WRKSRC}/src/Makefile.in

post-install:
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>

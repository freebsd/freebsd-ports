# New ports collection makefile for:	openyahtzee
# Date created:		04 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openyahtzee
PORTVERSION=	1.8.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Open%20Yahtzee/Open%20Yahtzee%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-featured classic dice game Yahtzee

GNU_CONFIGURE=	yes
USE_WX=		yes
USE_SQLITE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" MISSING="${TRUE} "

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|' ${WRKSRC}/Makefile.in\
		${WRKSRC}/src/Makefile.in
#	@${REINPLACE_CMD} -e '/am_missing_run=/s|=.*|="${TRUE} "|' ${WRKSRC}/configure

.include <bsd.port.mk>

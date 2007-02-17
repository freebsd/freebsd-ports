# New ports collection makefile for:	openyahtzee
# Date created:		04 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	OpenYahtzee
PORTVERSION=	1.7
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Full-featured classic dice game Yahtzee

GNU_CONFIGURE=	yes
USE_WX=		yes
USE_SQLITE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" MISSING="${TRUE} "
PLIST_FILES=	bin/${PORTNAME:L}

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|' ${WRKSRC}/Makefile.in ${WRKSRC}/src/Makefile.in
#	@${REINPLACE_CMD} -e '/am_missing_run=/s|=.*|="${TRUE} "|' ${WRKSRC}/configure

.include <bsd.port.mk>

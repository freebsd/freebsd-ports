# New ports collection makefile for:	tkhonyaku
# Date created:		10 July 2000
# Whom:			Daichi T.GOTO
#
# $FreeBSD$
#

PORTNAME=	tkhonyaku
PORTVERSION=	1.0
CATEGORIES=	japanese
MASTER_SITES=	http://www.yk.rim.or.jp/~kawagisi/

MAINTAINER=	daichi@ongs.net

RUN_DEPENDS=	${LOCALBASE}/bin/wish8.0jp:${PORTSDIR}/japanese/tk80

NO_BUILD=	yes

PLIST_SUB=	DISTNAME="${DISTNAME}"

pre-patch:
	${MKDIR} ${WRKSRC}
	@${MV} ${WRKSRC}/../colors.gif ${WRKSRC}
	@${MV} ${WRKSRC}/../tkhonyaku ${WRKSRC}
	@${MV} ${WRKSRC}/../tkhonyaku-readme ${WRKSRC}
	@${MV} ${WRKSRC}/../tkhonyaku.gif ${WRKSRC}
	@${MV} ${WRKSRC}/../tkhonyaku.xpm ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/share/doc/tkhonyaku
	${MKDIR} ${PREFIX}/tkhonyaku
	@${CP} ${WRKSRC}/tkhonyaku-readme ${PREFIX}/share/doc/tkhonyaku/
	@${CP} ${WRKSRC}/colors.gif ${PREFIX}/tkhonyaku
	@${CP} ${WRKSRC}/tkhonyaku.gif ${PREFIX}/tkhonyaku/
	@${CP} ${WRKSRC}/tkhonyaku.xpm ${PREFIX}/tkhonyaku/
	@${CP} ${WRKSRC}/tkhonyaku ${PREFIX}/bin

.include <bsd.port.mk>

# New ports collection makefile for:	tkhonyaku
# Date created:		10 July 2000
# Whom:			Daichi T.GOTO
#
# $FreeBSD$
#

PORTNAME=	tkhonyaku
PORTVERSION=	1.6
CATEGORIES=	japanese
MASTER_SITES=	http://www.yk.rim.or.jp/~kawagisi/

MAINTAINER=	daichi@ongs.gr.jp

RUN_DEPENDS=	${LOCALBASE}/bin/wish8.0jp:${PORTSDIR}/japanese/tk80

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${PERL} -i -pe 's,/usr/local/tkhonyaku,${PREFIX}/tkhonyaku,g' \
		${WRKSRC}/tkhonyaku ${WRKSRC}/tkhonyaku-readme

do-install:
	${MKDIR} ${PREFIX}/share/tkhonyaku
	${INSTALL_DATA} ${WRKSRC}/tkhonyaku.gif ${PREFIX}/share/tkhonyaku/
	${INSTALL_DATA} ${WRKSRC}/tkhonyaku.xpm ${PREFIX}/share/tkhonyaku/
	${INSTALL_DATA} ${WRKSRC}/colors.gif ${PREFIX}/share/tkhonyaku/
	${INSTALL_SCRIPT} ${WRKSRC}/tkhonyaku ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tkhonyaku
	${INSTALL_DATA} ${WRKSRC}/tkhonyaku-readme ${PREFIX}/share/doc/tkhonyaku/
.endif

.include <bsd.port.mk>

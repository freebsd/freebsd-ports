# Created by: chris_pressey@yahoo.ca
# $FreeBSD$

PORTNAME=	fargoal
PORTVERSION=	20040629
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/squidfighter/${PORTNAME}/20040630
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remake of classic roguelike game "Sword of Fargoal"

LIB_DEPENDS=	liballeg.so:${PORTSDIR}/devel/allegro

WRKSRC=		${WRKDIR}/${PORTNAME}/src

USES=		gmake zip

SUB_FILES=	${PORTNAME}-sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/../sword ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
.for f in agreement.txt data gfx sfx
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/../${f} ${STAGEDIR}${DATADIR}
.endfor

post-install:
	@${FIND} ${STAGEDIR}${DATADIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	@${FIND} ${STAGEDIR}${DATADIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} ${BINMODE}

.include <bsd.port.mk>

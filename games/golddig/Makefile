# Created by: jmz
# $FreeBSD$

PORTNAME=	golddig
PORTVERSION=	3.1
CATEGORIES=	games
MASTER_SITES=	http://www.NetBSD.org/~chuck/gz/
DISTNAME=	${PORTNAME}C${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Getting the Gold and Avoiding Death

USE_XORG=	x11
MAKE_ENV=	X11BASE="${LOCALBASE}"

LDFLAGS+=	-L${LOCALBASE}/lib

MAN6=		gdedit.6 golddig.6

DESKTOP_ENTRIES="Gold Digger" "" "" "${PORTNAME}" "" ""

NO_STAGE=	yes
post-patch:
	@${GREP} -lR "@PREFIX@" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|@PREFIX@|${PREFIX}|'

.include <bsd.port.mk>

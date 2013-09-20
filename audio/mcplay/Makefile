# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	mcplay
DISTVERSION=	0.3i
CATEGORIES=	audio
MASTER_SITES=	http://www.yahuxo.de/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses based front-end to various audio players

LICENSE=	GPLv2

LIB_DEPENDS=	glib-12:${PORTSDIR}/devel/glib12

NO_STAGE=	yes
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

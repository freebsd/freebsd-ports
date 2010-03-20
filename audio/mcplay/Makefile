# Ports collection makefile for:	mcplay
# Date created:		18 Mar 2010
# Whom:			Charlie Kester <corky1951@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	mcplay
DISTVERSION=	0.3i
CATEGORIES=	audio
MASTER_SITES=	http://www.yahuxo.de/${PORTNAME}/

MAINTAINER=	corky1951@comcast.net
COMMENT=	A curses based front-end to various audioplayers

LIB_DEPENDS=	glib-12:${PORTSDIR}/devel/glib12

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		${PORTNAME}.1
MANCOMPRESSED=	no
.endif

PLIST_FILES=		bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	biorythm
# Date created:				4 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	biorythm
PORTVERSION=	1.1.1
CATEGORIES=	games
MASTER_SITES=	http://shh.thathost.com/pub-unix/files/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	shhmsg.1:${PORTSDIR}/devel/libshhmsg \
		shhopt.1:${PORTSDIR}/devel/libshhopt

USE_GMAKE=	yes

MAN6=		biorythm.6

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/biorythm
.for file in CREDITS ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/biorythm
.endfor
.endif

.include <bsd.port.mk>

# ports collection makefile for:   lame
# Date created:        11 January 1998
# Whom:                yoshiaki Uchikawa
#
# $FreeBSD$
#

PORTNAME=	lame
PORTVERSION=	3.70
CATEGORIES=	audio
MASTER_SITES=	http://lame.sourceforge.net/download/beta/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	yoshiaki@kt.rim.or.jp

USE_GMAKE=	yes
WANT_GTK=	yes
ALL_TARGET=	lame
RESTRICTED=	Condition is not clear

MAN1=		lame.1

.include <bsd.port.pre.mk>

.if defined(HAVE_GTK)
USE_GTK=	yes
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lame ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man/lame.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/lame
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html \
	 ${WRKSRC}/doc/html/*.css ${PREFIX}/share/doc/lame
.endif

.include <bsd.port.post.mk>

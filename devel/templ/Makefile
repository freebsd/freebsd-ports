# New ports collection makefile for:    templ
# Date created:         14 Jun 1999
# Whom:                 Oh Junseon <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	templ
PORTVERSION=	0.3
CATEGORIES=	devel
MASTER_SITES= 	ftp://ftp.holywar.net/pub/templ/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	hollywar@mail.holywar.net
COMMENT=	Source code templates generator

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/templates
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/templates
.endif

.include <bsd.port.mk>

# New ports collection makefile for:    templ
# Date created:         14 Jun 1999
# Whom:                 Oh Junseon <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	templ
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.holywar.net/pub/templ/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Source code templates generator

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/templates
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/templates
.endif

.include <bsd.port.mk>

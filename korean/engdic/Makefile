# New ports collection makefile for:    engdic-0.2
# Date created:         3 Jun 1999
# Whom:                 Oh Junseon <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	engdic
PORTVERSION=	0.2
CATEGORIES=	korean deskutils
MASTER_SITES=	ftp://ftp.holywar.net/pub/engdic/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	hollywar@mail.holywar.net
COMMENT=	An English dictionary utility for Korean

ALL_TARGET=	clean all
USE_REINPLACE=	yes

post-patch:
	@for f in ${WRKSRC}/Makefile ${WRKSRC}/engdic.h; do \
		${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' $$f; \
	done

.include <bsd.port.mk>

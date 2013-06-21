# Created by: Oh Junseon <hollywar@mail.holywar.net>
# $FreeBSD$

PORTNAME=	engdic
PORTVERSION=	0.2
CATEGORIES=	korean deskutils
MASTER_SITES=	ftp://ftp.holywar.net/pub/engdic/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	English dictionary utility for Korean

ALL_TARGET=	clean all

post-patch:
	@for f in ${WRKSRC}/Makefile ${WRKSRC}/engdic.h; do \
		${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' $$f; \
	done

.include <bsd.port.mk>

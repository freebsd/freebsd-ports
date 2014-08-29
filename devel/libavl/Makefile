# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libavl
PORTVERSION=	1.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	avl
DISTNAME=	avl-${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Library for balanced binary trees

GNU_CONFIGURE=	yes

INFO=		avl

post-patch:
	${REINPLACE_CMD} -e '/echo.*RANLIB/,+1d' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

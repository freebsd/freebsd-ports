# Created by: Karl Dietz (Karl.Dietz@frankfurt.netsurf.de)
# $FreeBSD$

PORTNAME=	dnsutl
PORTVERSION=	1.12
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs to make using DNS easier

LIB_DEPENDS=	libexplain.so:devel/libexplain

BROKEN_armv6=		fails to package: FAILED test of common/srrf.c file
BROKEN_armv7=		fails to package: FAILED test of common/srrf.c file

GNU_CONFIGURE=	yes
ALL_TARGET=	all sure
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes
USES=		groff

post-install:
	${INSTALL_MAN} ${WRKSRC}/man1/*.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>

PORTNAME=	dnsutl
PORTVERSION=	1.12
PORTREVISION=	3
CATEGORIES=	dns
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs to make using DNS easier
WWW=		https://dnsutl.sourceforge.net/

LIB_DEPENDS=	libexplain.so:devel/libexplain

BROKEN_aarch64=		fails to package: FAILED test of common/srrf.c file
BROKEN_armv6=		fails to package: FAILED test of common/srrf.c file
BROKEN_armv7=		fails to package: FAILED test of common/srrf.c file

GNU_CONFIGURE=	yes
ALL_TARGET=	all sure
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes
USES=		groff

post-install:
	${INSTALL_MAN} ${WRKSRC}/man1/*.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

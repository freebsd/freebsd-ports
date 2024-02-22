PORTNAME=	bonnie
PORTVERSION=	2.0.6
PORTREVISION=	2
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.textuality.com/bonnie/
DISTNAME=	bonnie

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Performance Test of Filesystem I/O
WWW=		https://www.textuality.com/bonnie/

NO_WRKSUBDIR=	yes
MAKE_ARGS+=	-e CFLAGS="${CFLAGS}"
ALL_TARGET=	bsd
PLIST_FILES=	bin/bonnie share/man/man1/bonnie.1.gz

OPTIONS_DEFINE=	STATIC

STATIC_CFLAGS+=	-static

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Bonnie ${STAGEDIR}${PREFIX}/bin/bonnie
	${INSTALL_MAN} ${FILESDIR}/bonnie.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

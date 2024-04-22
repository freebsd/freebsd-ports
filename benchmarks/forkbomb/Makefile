PORTNAME=	forkbomb
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	benchmarks
MASTER_SITES=	SUNSITE/system/benchmark \
		http://home.tiscali.cz:8080/~cz210552/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System stress testing tool
WWW=		http://home.tiscali.cz/~cz210552/forkbomb.html

LICENSE=	PD

PLIST_FILES=	sbin/forkbomb \
		share/man/man8/forkbomb.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's|man/man8|share/man/man8|' ${WRKSRC}/Makefile

.include <bsd.port.mk>

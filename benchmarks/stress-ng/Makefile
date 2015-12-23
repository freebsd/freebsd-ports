# $FreeBSD$

PORTNAME=	stress-ng
PORTVERSION=	0.04.21
CATEGORIES=	benchmarks
MASTER_SITES=	http://kernel.ubuntu.com/~cking/tarballs/stress-ng/

MAINTAINER=	luca.pizzamiglio@gmail.com
COMMENT=	Stress test benchmarks

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		unfetchable

ALL_TARGET=	# empty

PLIST_FILES=	bin/stress-ng man/man1/stress-ng.1.gz

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-stress-cpu.c \
		${FILESDIR}/extrapatch-Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stress-ng ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/stress-ng.1 ${STAGEDIR}${MANDIRS}/man1

.include <bsd.port.post.mk>

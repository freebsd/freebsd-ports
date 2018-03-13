# $FreeBSD$

PORTNAME=	stress-ng
PORTVERSION=	0.09.19
CATEGORIES=	benchmarks
MASTER_SITES=	http://kernel.ubuntu.com/~cking/tarballs/stress-ng/

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Stress test benchmarks

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	Fails to link: missing sbrk

USES=		compiler:c11 gmake tar:xz
ALL_TARGET=	# empty

PLIST_FILES=	bin/stress-ng man/man1/stress-ng.1.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200056 && ${ARCH} == i386
BROKEN=	undefined reference to '__atomic_fetch_add_8'
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stress-ng ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/stress-ng.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>

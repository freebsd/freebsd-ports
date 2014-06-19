# Created by: Ada T Lim <ada@not-enough.bandwidth.org>
# $FreeBSD$

PORTNAME=	hztty
PORTVERSION=	2.0
CATEGORIES=	chinese
MASTER_SITES=	ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/convert/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translator between GuoBiao / Big5 and HZ

ALL_TARGET=	bsd
PLIST_FILES=	bin/hztty man/man1/${PORTNAME}.1.gz

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.post.mk>

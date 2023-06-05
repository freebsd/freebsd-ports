PORTNAME=	ish
PORTVERSION=	2.01a5
CATEGORIES=	converters
MASTER_SITES=	http://www.unix.gr.jp/jnetcex/soft/\
		PORTS_JP
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Binary-to-text file-encoder

LICENSE=	NONE

MAKEFILE=	makefile
MAKE_ARGS=	CFLAGS="${CFLAGS}" DEST=${PREFIX}/bin
ALL_TARGET=	ish

PLIST_FILES=	bin/ish

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ish ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>

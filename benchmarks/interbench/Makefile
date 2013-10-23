# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	interbench
DISTVERSION=	0.31
CATEGORIES=	benchmarks
MASTER_SITES=	http://ck.kolivas.org/apps/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactivity benchmark for Unix-like systems

LICENSE=	GPLv2

USE_BZIP2=	yes
USES=		gmake
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

MAN8=		${PORTNAME}.8
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	readme readme.interactivity

OPTIONS_DEFINE=	DOCS

post-patch:
# Do not confuse the reader that this program is Linux-specific
	@${REINPLACE_CMD} -e '/kernel/!s,Linux,Unix-like systems, ; \
		/kernel/s,Linux,the,' ${WRKSRC}/${MAN8}

pre-build:
# Remove stale Linuxish object files and binaries; setting ALL_TARGET to
# "clean ${PORTNAME}" turned out to be racy and breaking parallel builds
	${MAKE} -C ${BUILD_WRKSRC} clean

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${STAGEDIR}${MANPREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

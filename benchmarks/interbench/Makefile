# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	interbench
DISTVERSION=	0.31
CATEGORIES=	benchmarks
MASTER_SITES=	http://ck.kolivas.org/apps/interbench/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Interactivity benchmark for Unix-like systems

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	clean ${PORTNAME}
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	readme readme.interactivity

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not build, requires sqrtl(3)
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>

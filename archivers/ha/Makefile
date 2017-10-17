# Created by: ache
# $FreeBSD$

PORTNAME=	ha
PORTVERSION=	0.999b
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	https://aklv.github.io/distfiles/
DISTNAME=	ha0999

MAINTAINER=	ak@FreeBSD.org
COMMENT=	File archiver based on HSC compression method

LICENSE=	GPLv2

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/ha
MAKEFILE=	makefile.nix
ALL_TARGET=	ha
USES=		gmake tar:tgz

post-patch:
	@${REINPLACE_CMD} 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/c/hsc.c ${WRKSRC}/c/cpy.c ${WRKSRC}/c/asc.c
	@${REINPLACE_CMD} -e 's|CC =|CC ?=|' \
		-e 's|LDFLAGS = -O2||' \
		-e 's|CFLAGS = -Wall -O2|CFLAGS += -Wall|' \
		${WRKSRC}/makefile.nix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ha ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

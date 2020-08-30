# Created by: Jos Backus <jos@catnook.com>
# $FreeBSD$

PORTNAME=	buildtool
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of portable software build utilities

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-p ${PREFIX} -d ${DOCSDIR}

CFLAGS+=	-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01


OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e "s/dprintf/debug_printf/g" \
		${WRKSRC}/bt_sh/output.h ${WRKSRC}/bt_sh/input.c \
		${WRKSRC}/bt_sh/input.c ${WRKSRC}/bt_sh/output.c

.include <bsd.port.mk>

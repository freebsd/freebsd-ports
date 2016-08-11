# Created by: Jos Backus <jos@catnook.com>
# $FreeBSD$

PORTNAME=	buildtool
PORTVERSION=	0.16
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of portable software build utilities

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-p ${PREFIX} -d ${DOCSDIR}

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e "s/dprintf/debug_printf/g" \
		${WRKSRC}/bt_sh/output.h ${WRKSRC}/bt_sh/input.c \
		${WRKSRC}/bt_sh/input.c ${WRKSRC}/bt_sh/output.c

.include <bsd.port.mk>

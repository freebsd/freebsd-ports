# New ports collection makefile for:	tdl
# Date created:				30 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	tdl
PORTVERSION=	1.5.2
CATEGORIES=	devel
MASTER_SITES=	http://www.rpcurnow.force9.co.uk/tdl/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	To-do list manager

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}"

MAN1=	tdl.1
MLINKS=	tdl.1 tdla.1 tdl.1 tdll.1 tdl.1 tdld.1 tdl.1 tdlg.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>

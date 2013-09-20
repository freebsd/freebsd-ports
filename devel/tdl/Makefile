# Created by: petef
# $FreeBSD$

PORTNAME=	tdl
PORTVERSION=	1.5.2
CATEGORIES=	devel
MASTER_SITES=	http://www.rpcurnow.force9.co.uk/tdl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	To-do list manager

CONFLICTS=	devtodo-[0-9]*

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}

MAN1=	tdl.1
MLINKS=	tdl.1 tdla.1 tdl.1 tdll.1 tdl.1 tdld.1 tdl.1 tdlg.1
MANCOMPRESSED=	yes

NO_STAGE=	yes
.include <bsd.port.mk>

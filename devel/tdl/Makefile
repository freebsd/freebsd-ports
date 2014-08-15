# Created by: petef
# $FreeBSD$

PORTNAME=	tdl
PORTVERSION=	1.5.2
CATEGORIES=	devel
MASTER_SITES=	http://www.rpcurnow.force9.co.uk/tdl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	To-do list manager

CONFLICTS=	devtodo-[0-9]*

USES=		readline

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=--prefix=${PREFIX} --readline-dir=${LOCALBASE}

post-patch:
	${REINPLACE_CMD} -e 's/-R\$$/-Wl,-rpath,$$/' ${WRKSRC}/configure

.include <bsd.port.mk>

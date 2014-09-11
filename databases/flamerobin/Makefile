# Created by: dindin
# $FreeBSD$

PORTNAME=	flamerobin
PORTVERSION=	0.9.2
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI administration tool for firebird database

LICENSE=	expat
LICENSE_NAME=	FlameRobin Expat
LICENSE_FILE=	${WRKSRC}/docs/fr_license.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_FIREBIRD=	yes
USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_CONF_ARGS=	absolute
WX_PREMK=	yes
WX_UNICODE=	yes

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

.include <bsd.port.mk>

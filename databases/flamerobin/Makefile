# Created by: dindin
# $FreeBSD$

PORTNAME=	flamerobin
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The GUI administration tool for firebird database

USE_FIREBIRD=	yes
USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_CONF_ARGS=	absolute
WX_PREMK=	yes
WX_UNICODE=	yes

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message
MAN1=		flamerobin.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

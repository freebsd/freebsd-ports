# New ports collection makefile for:  flamerobin
# Date created:        5 April 2006
# Whom:            dindin
#
# $FreeBSD$
#

PORTNAME=	flamerobin
PORTVERSION=	0.9.2
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
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

SUB_FILES=	pkg-message
MAN1=		flamerobin.1

.include <bsd.port.pre.mk>

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

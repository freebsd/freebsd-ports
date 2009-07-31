# New ports collection makefile for:  flamerobin
# Date created:        5 April 2006
# Whom:            dindin
#
# $FreeBSD$
#

PORTNAME=	flamerobin
PORTVERSION=	0.7.6
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	dindin@FreeBSD.org.ua
COMMENT=	The GUI administration tool for firebird database

LIB_DEPENDS=	fbclient.2:${PORTSDIR}/databases/firebird20-client

USE_WX=		2.6+
WX_COMPS=	wx contrib
WX_CONF_ARGS=	absolute
WX_PREMK=	yes
WX_UNICODE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

SUB_FILES=	pkg-message
MAN1=		flamerobin.1

.include <bsd.port.pre.mk>

.if exists(${WX_CONFIG})
WX_VER_STR!=	${WX_CONFIG} --release
PLIST_SUB+=	WX_VERSION=${WX_VER_STR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

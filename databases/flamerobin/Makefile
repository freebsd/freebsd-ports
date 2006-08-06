# New ports collection makefile for:  flamerobin
# Date created:        5 April 2006
# Whom:            dindin
#
# $FreeBSD$
#

PORTNAME=	flamerobin
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://dindin.webkazan.ru/flamerobin/\
		http://main.webkazan.ru/flamerobin/\
		http://superb-west.dl.sourceforge.net/sourceforge/flamerobin/
DISTNAME=	flamerobin-0.7.2-src

MAINTAINER=	dindin@FreeBSD.org.ua
COMMENT=	The GUI administration tool for firebird database

LIB_DEPENDS=	fbclient.1:${PORTSDIR}/databases/firebird-client

USE_WX=		2.6
WX_COMPS=	wx contrib
WX_UNICODE=	yes

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

WX_CONFIG=	${X11BASE}/bin/wxgtk2u-2.6-config

SUB_FILES=	pkg-message
MAN1=		flamerobin.1

.if exists(${WX_CONFIG})
WX_VERSION!=	${WX_CONFIG} --release
PLIST_SUB+=	WX_VERSION=${WX_VERSION}
.endif

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.x
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

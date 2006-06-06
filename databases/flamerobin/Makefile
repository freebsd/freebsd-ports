# New ports collection makefile for:  flamerobin
# Date created:        5 April 2006
# Whom:            dindin
#
# $FreeBSD$
#

PORTNAME=	flamerobin
PORTVERSION=	0.7.2
CATEGORIES=	databases
MASTER_SITES=	http://dindin.webkazan.ru/flamerobin/ \
		http://superb-west.dl.sourceforge.net/sourceforge/flamerobin/
DISTNAME=	flamerobin-0.7.2-src

MAINTAINER=	dindin@FreeBSD.org.ua
COMMENT=	An GUI administration tool for firebird database

WXPORT=		gtk2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

BUILD_DEPENDS+=	${WX_CONFIG}:${PORTSDIR}/x11-toolkits/wxgtk26
WX_CONFIG=	${X11BASE}/bin/wxgtk2-2.6-config

SUB_FILES=	pkg-message
MAN1=		flamerobin.1

.if exists(${WX_CONFIG})
WX_VERSION!=	${WX_CONFIG} --release
PLIST_SUB+=	WX_VERSION=${WX_VERSION}
.endif

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}

LIB_DEPENDS+=	wx_gtk2_stc-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26-contrib

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

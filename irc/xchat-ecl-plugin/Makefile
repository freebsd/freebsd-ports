# New ports collection makefile for:	xchat-ecl-plugin
# Date Created:				Sep 17 2004
# Whom:					Julian Stecklina <der_julian@web.de>
#
# $FreeBSD$
#

PORTNAME=	xchat-ecl-plugin
PORTVERSION=	0.3
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xchatlisp
DISTNAME=	eclplugin-${PORTVERSION}

MAINTAINER=	der_julian@web.de
COMMENT=	X-Chat 2.x plugin to allow Common Lisp scripting

BUILD_DEPENDS=	ecl:${PORTSDIR}/lang/ecl
RUN_DEPENDS=	xchat:${PORTSDIR}/irc/xchat2

INFO=		xchatlisp

WRKSRC=		${WRKDIR}/eclplugin-${PORTVERSION}
USE_X_PREFIX=	yes

PLIST_FILES=	lib/xchat/plugins/ecl.so

do-build:
		( cd ${BUILD_WRKSRC} && make ecl.so )
		( cd ${BUILD_WRKSRC}/doc && make xchatlisp.info )

do-install:
		${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ecl.so ${PREFIX}/lib/xchat/plugins/
		${INSTALL_MAN} ${BUILD_WRKSRC}/doc/xchatlisp.info ${PREFIX}/info/

.include <bsd.port.mk>

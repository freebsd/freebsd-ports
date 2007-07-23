# New ports collection makefile for:   mcpp
# Date created:		06 April 2007
# Whom:			Kiyoshi Matsui <kmatsui@t3.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	mcpp
PORTVERSION=	2.6.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://prdownloads.sourceforge.net/mcpp/ \
		http://jaist.dl.sourceforge.net/sourceforge/mcpp/

MAINTAINER=	kmatsui@t3.rim.or.jp
COMMENT=	Alternative C/C++ preprocessor

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAN1=		mcpp.1

PLIST_FILES=	bin/mcpp    \
		share/doc/mcpp/LICENSE  \
		share/doc/mcpp/NEWS     \
		share/doc/mcpp/README   \
		share/doc/mcpp/mcpp-manual.html  \
		share/doc/mcpp/mcpp-manual-jp.html
PLIST_DIRS=	share/doc/mcpp

.include <bsd.port.mk>

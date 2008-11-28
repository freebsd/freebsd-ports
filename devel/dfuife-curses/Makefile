# New ports collection makefile for:   dfuife-curses
# Date created:        20 April 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	dfuife-curses
PORTVERSION=	1.5.1.20050829
CATEGORIES=	devel
MASTER_SITES=	http://exodus.xmms.se/~alex/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DFUI curses frontend

LIB_DEPENDS=	aura3.3:${PORTSDIR}/devel/libaura \
		dfui4.4:${PORTSDIR}/devel/libdfui

USE_BZIP2=	yes

PLIST_FILES=	bin/dfuife_curses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dfuife_curses ${PREFIX}/bin

.include <bsd.port.mk>

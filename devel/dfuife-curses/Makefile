# Created by: Andrew Turner <andrew+ports@fubar.geek.nz>
# $FreeBSD$

PORTNAME=	dfuife-curses
PORTVERSION=	1.5.1.20050829
CATEGORIES=	devel
MASTER_SITES=	http://people.xmms2.org/~alex/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DFUI curses frontend

LIB_DEPENDS=	libaura3.so:${PORTSDIR}/devel/libaura \
		libdfui4.so:${PORTSDIR}/devel/libdfui

USE_BZIP2=	yes

PLIST_FILES=	bin/dfuife_curses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dfuife_curses ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

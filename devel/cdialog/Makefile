# Created by: AlanE <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cdialog
PORTVERSION=	1.1.20120215
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/${PORTNAME:S|^c||}/
DISTNAME=	${PORTNAME:S|^c||}-${PORTVERSION:R}-${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced version of 'dialog' to work with ncurses

OPTIONS_DEFINE=	EXAMPLES

LICENSE=	LGPL21

USES=		ncurses

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-widec \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--with-libtool \
		--with-ncursesw \
		--with-package=${PORTNAME}
MAKEFILE=	makefile

INSTALL_TARGET=	install-strip install-man install-lib

.include <bsd.port.pre.mk>

.if ${NCURSESBASE} != /usr
CONFIGURE_ARGS+=	--with-curses-dir=${NCURSESBASE}
.endif

post-patch:
	@${FIND} ${WRKSRC}/samples/ -type f -exec ${REINPLACE_CMD} -i "" "s|dialog|cdialog|g" {} \;

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>

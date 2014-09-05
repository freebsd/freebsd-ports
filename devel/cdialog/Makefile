# $FreeBSD$

PORTNAME=	cdialog
PORTVERSION=	1.2.20140219
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/${PORTNAME:S|^c||}/
DISTNAME=	${PORTNAME:S|^c||}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced version of 'dialog' to work with ncurses

LICENSE=	LGPL21

OPTIONS_DEFINE=	EXAMPLES

USES=		ncurses	libtool tar:tgz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-widec \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--with-libtool \
		--with-ncursesw \
		--with-package=${PORTNAME}
MAKEFILE=	makefile

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool

INSTALL_TARGET=	install-strip install-man install-lib

.include <bsd.port.pre.mk>

.if ${NCURSESBASE} != /usr
CONFIGURE_ARGS+=	--with-curses-dir=${NCURSESBASE}
.endif

post-patch:
	@${FIND} ${WRKSRC}/samples/ -type f -exec ${REINPLACE_CMD} -i "" "s|dialog|cdialog|g" {} \;
	@${REINPLACE_CMD} -e 's|$$(INSTALL_DATA) $$(LIB)|$$(INSTALL_DATA) -s $$(LIB)|'\
		${WRKSRC}/${MAKEFILE}.in

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>

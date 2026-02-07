PORTNAME=	dialog
DISTVERSION=	1.3-20251223
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	https://invisible-island.net/archives/${PORTNAME}/ \
		https://invisible-mirror.net/archives/${PORTNAME}/
PKGNAMEPREFIX=	c

MAINTAINER=	jcpierri@gmail.com
COMMENT=	Enhanced version of 'dialog' to work with ncurses
WWW=		https://invisible-island.net/dialog/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool:build ncurses tar:tgz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-widec \
		--includedir=${PREFIX}/include/${PKGNAMEPREFIX}${PORTNAME} \
		--with-libtool \
		--with-${NCURSES_IMPL} \
		--with-package=${PKGNAMEPREFIX}${PORTNAME}\
		--with-curses-dir=${NCURSESBASE}
MAKEFILE=	makefile
INSTALL_TARGET=	install-strip install-man install-lib
TEST_TARGET=	check
OPTIONS_DEFINE=	EXAMPLES

pre-patch-EXAMPLES-on:
	@${FIND} ${WRKSRC}/samples/ -type f -exec \
		${REINPLACE_CMD} -i "" "s|\<dialog\>|${PKGNAMEPREFIX}${PORTNAME}|g" {} \;

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcdialog.so

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	cdialog
DISTVERSION=	1.3.20180621
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.invisible-island.net/${PORTNAME:S|^c||}/
DISTNAME=	${PORTNAME:S|^c||}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	jcpierri@gmail.com
COMMENT=	Enhanced version of 'dialog' to work with ncurses

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool:build ncurses tar:tgz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-widec \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--with-libtool \
		--with-${NCURSES_IMPL} \
		--with-package=${PORTNAME}
MAKEFILE=	makefile

INSTALL_TARGET=	install-strip install-man install-lib

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${NCURSESBASE} != /usr
CONFIGURE_ARGS+=	--with-curses-dir=${NCURSESBASE}
.endif

post-patch:
	@${FIND} ${WRKSRC}/samples/ -type f -exec ${REINPLACE_CMD} -i "" "s|dialog|cdialog|g" {} \;
	@${REINPLACE_CMD} -e 's|$$(INSTALL_DATA) $$(LIB)|$$(INSTALL_DATA) -s $$(LIB)|'\
		${WRKSRC}/${MAKEFILE}.in

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>

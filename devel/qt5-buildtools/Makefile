# $FreeBSD$

PORTNAME=	buildtools
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt build tools

USE_QT5=	qmake_build
QT_DIST=	base
USES=		perl5
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-no-gui -no-xcb
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/tools/bootstrap
INSTALL_WRKSRC=	${BUILD_WRKSRC}

MORE_WRKSRCS=	src/tools/moc \
		src/tools/rcc

post-build:
.for d in ${MORE_WRKSRCS}
	@cd ${WRKSRC}/${d} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}
.endfor

post-install:
.for d in ${MORE_WRKSRCS}
	@cd ${WRKSRC}/${d} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} ${INSTALL_TARGET}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/syncqt.pl \
		${STAGEDIR}${PREFIX}/${QT_BINDIR_REL}/syncqt.pl

.include <bsd.port.mk>

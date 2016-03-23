# $FreeBSD$

PORTNAME=	qqwing
PORTVERSION=	1.3.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	games gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sudoku generating and solving software

USE_GITHUB=	yes
GH_ACCOUNT=	stephenostermiller

USES=		autoreconf:build gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
INSTALL_TARGET=	install-strip

CONFIGURE_WRKSRC=	${WRKSRC}/target/automake
BUILD_WRKSRC=		${WRKSRC}/target/automake
INSTALL_WRKSRC=		${WRKSRC}/target/automake

pre-configure:
	@${MKDIR} ${WRKSRC}/target/automake
	@cd ${WRKSRC} && ${CP} build/configure.ac build/Makefile.am \
		build/qqwing.pc.in doc/README doc/AUTHORS doc/COPYING \
		target/automake
	@cd ${WRKSRC} && ${CP} doc/qqwing.man target/automake/qqwing.1
	@cd ${WRKSRC}/target/automake && ${TOUCH} config.h.in
	@cd ${WRKSRC}/target/automake && ${AUTORECONF} --force --install

pre-build:
	@cd ${WRKSRC} && ${CP} src/cpp/*.cpp target/automake
	@cd ${WRKSRC} && ${CP} src/cpp/*.hpp target/automake

.include <bsd.port.mk>

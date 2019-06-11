# $FreeBSD$

PORTNAME=	plexil
DISTVERSION=	4.5.0
DISTVERSIONSUFFIX=	RC2
CATEGORIES=	lang devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION:R}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PLan EXecution Interchange Language from NASA for robot control

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --disable-gantt --disable-ipc --disable-sas --disable-test-exec --disable-udp
USE_GCC=	yes # clang fails: undefined symbol: std::__1::unique_ptr
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

WRKSRC_SUBDIR=	src

BINARY_ALIAS=	gcc=${CC}

.include <bsd.port.mk>

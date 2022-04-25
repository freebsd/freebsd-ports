PORTNAME=	plexil
DISTVERSION=	4.5.0
PORTREVISION=	2
DISTVERSIONSUFFIX=	RC3
CATEGORIES=	lang devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION:R}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PLan EXecution Interchange Language from NASA for robot control

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --disable-gantt --disable-ipc --disable-sas --disable-test-exec --disable-udp

INSTALL_TARGET=	install-strip

WRKSRC_SUBDIR=	src

BINARY_ALIAS=	gcc=${CC}

LDFLAGS+=	-lexecinfo

post-patch: # workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=263535
	@${REINPLACE_CMD} -e 's|std::unique_ptr|std::shared_ptr|' \
		${WRKSRC}/value/Value.hh \
		${WRKSRC}/value/Value.cc

.include <bsd.port.mk>

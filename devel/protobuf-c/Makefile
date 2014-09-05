# Created by: Aaron Hurt <ahurt@anbcs.com>
# $FreeBSD$

PORTNAME=	protobuf-c
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${GITHUB_USER}/${GITHUB_REPO}/releases/download/v${PORTVERSION}/ \
		http://github.com/${GITHUB_USER}/${GITHUB_REPO}/releases/download/v${PORTVERSION}/

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Code generator and libraries to use Protocol Buffers from pure C

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf.so:${PORTSDIR}/devel/protobuf

USES=		gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GITHUB_USER=	protobuf-c
GITHUB_REPO=	protobuf-c

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

ALL_TARGET=	all
.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
ALL_TARGET+=	html-local
.endif


post-patch:
	@${REINPLACE_CMD} -e 's|GREP "\\-L"|GREP "bin/ld"|g' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libprotobuf-c.so.1.0.0
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/html/* ${STAGEDIR}${DOCSDIR}/html
.endif

tests: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>

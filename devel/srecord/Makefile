# Created by: ijliao
# $FreeBSD$

PORTNAME=	srecord
PORTVERSION=	1.64
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Collection of powerful tools for manipulating EPROM load files

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

USES=		ghostscript libtool:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

HEADER_DIRS=	input \
		input/file \
		input/filter \
		input/filter/checksum \
		input/filter/interval \
		input/filter/message \
		input/generator \
		memory \
		memory/walker \
		output \
		output/file \
		quit

OPTIONS_DEFINE=	DOCS

post-build:
	cd ${WRKSRC} && ${MAKE_CMD} libdir/pkgconfig/srecord.pc

pre-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${MKDIR} ${HEADER_DIRS:S,^,${STAGEDIR}${PREFIX}/include/${PORTNAME}/,}

post-install:
	chmod 644 ${STAGEDIR}${PREFIX}/lib/libsrecord.so.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsrecord.so.0
	chmod 444 ${STAGEDIR}${PREFIX}/lib/libsrecord.so.0
	${INSTALL_DATA} ${WRKSRC}/libdir/pkgconfig/srecord.pc \
	    ${STAGEDIR}${PREFIX}/libdata/pkgconfig

test:
	@cd ${WRKSRC} && ${MAKE} sure

build-plist:
	${RM} -f ${PLIST}
	${MAKE} makeplist | \
	    ${GREP} -v /you/have/to/check/what/makeplist/gives/you >> ${PLIST}

.include <bsd.port.mk>

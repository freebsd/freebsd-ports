# Created by: Steven G. Kargl
# $FreeBSD$

PORTNAME=	f2c
PORTVERSION=	20060810
PORTREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	LOCAL/maho/f2c
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Fortran-to-C converter and its run-time libraries

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip

GUNZIP_CMD=	minigzip -d
USES=		gmake
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	LEAD_0
LEAD_0_DESC=	Print with leading zeros

# Set FCNAME to the name of the Fortran 77 / F2C wrapper.
FCNAME?=	fc
PLIST_SUB=	FCNAME=${FCNAME}
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFC}
PLIST_SUB+=	FC=""
.else
PLIST_SUB+=	FC="@comment "
.endif

PORTDOCS=	00lastchange README README_libf2c changes f2c.pdf permission

.include <bsd.port.pre.mk>

post-extract:
	cd ${WRKSRC} && ${FIND} . -name "*.gz" | ${XARGS} ${GUNZIP_CMD}
	cd ${WRKSRC} && ${UNZIP_CMD} libf2c.zip
	${CP} -p ${WRKSRC}/libf2c/README ${WRKSRC}/README_libf2c

pre-patch:
	${CP} -p ${WRKSRC}/libf2c/makefile.u ${WRKSRC}/libf2c/Makefile
	${CP} -p ${WRKSRC}/src/makefile.u ${WRKSRC}/src/Makefile

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/fc
.if ${PORT_OPTIONS:MLEAD_0}
	${REINPLACE_CMD} -e 's|CFLAGS += -fPIC|CFLAGS += -fPIC -DWANT_LEAD_0|' ${WRKSRC}/libf2c/Makefile
	${REINPLACE_CMD} -e 's|#CFLAGS = -O|CFLAGS = -O -DWANT_LEAD_0|' ${WRKSRC}/src/Makefile
.endif



do-build:
	@${ECHO_MSG} "===> Building f2c..."
	@(cd ${WRKSRC}/src;	\
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	@${ECHO_MSG} "===> Building libf2c..."
	@(cd ${WRKSRC}/libf2c;	\
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET} libf2c.so)
	${MV} ${WRKSRC}/libf2c/libf2c.so ${WRKSRC}/libf2c/libf2c.so.2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/f2c ${STAGEDIR}${PREFIX}/bin
.if defined(WITH_MFC)
	${INSTALL_SCRIPT} ${WRKSRC}/fc ${STAGEDIR}${PREFIX}/bin/${FCNAME}
.endif
	${INSTALL_DATA} ${WRKSRC}/src/f2c.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/src/f2c.1t ${STAGEDIR}${MAN1PREFIX}/man/man1/f2c.1
	${INSTALL_DATA} ${WRKSRC}/libf2c/libf2c.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libf2c/libf2c.so.2 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libf2c.so.2 ${STAGEDIR}${PREFIX}/lib/libf2c.so

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>

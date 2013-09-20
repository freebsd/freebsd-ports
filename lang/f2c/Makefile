# Created by: Steven G. Kargl
# $FreeBSD$

PORTNAME=	f2c
PORTVERSION=	20060810
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	maho/f2c
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Fortran-to-C converter and its run-time libraries

EXTRACT_DEPENDS=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip

GUNZIP_CMD=	minigzip -d
USE_GMAKE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	LEAD_0
LEAD_0_DESC=	Print with leading zeros


# Set FCNAME to the name of the Fortran 77 / F2C wrapper.
FCNAME?=	fc
PLIST_SUB=	FCNAME=${FCNAME}
NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFC}
PLIST_SUB+=	FC=""
.else
PLIST_SUB+=	FC="@comment "
.endif

MAN1=		f2c.1

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
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	@${ECHO_MSG} "===> Building libf2c..."
	@(cd ${WRKSRC}/libf2c;	\
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET} libf2c.so)
	${MV} ${WRKSRC}/libf2c/libf2c.so ${WRKSRC}/libf2c/libf2c.so.2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/f2c ${PREFIX}/bin
.if defined(WITH_MFC)
	${INSTALL_SCRIPT} ${WRKSRC}/fc ${PREFIX}/bin/${FCNAME}
.endif
	${INSTALL_DATA} ${WRKSRC}/src/f2c.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/src/${MAN1}t ${MAN1PREFIX}/man/man1/${MAN1}
	${INSTALL_DATA} ${WRKSRC}/libf2c/libf2c.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libf2c/libf2c.so.2 ${PREFIX}/lib
	${LN} -sf libf2c.so.2 ${PREFIX}/lib/libf2c.so

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>

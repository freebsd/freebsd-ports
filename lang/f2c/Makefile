# Created by: Steven G. Kargl
# $FreeBSD$

PORTNAME=	f2c
PORTVERSION=	20060810
PORTREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	LOCAL/maho/f2c
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	fortran@FreeBSD.org
COMMENT=	Fortran-to-C converter and its run-time libraries

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip

GUNZIP_CMD=	minigzip -d
USES=		gmake
USE_LDCONFIG=	yes

LIBVER=		2

# Set FCNAME to the name of the Fortran 77 / F2C wrapper.
FCNAME?=	fc
PLIST_SUB=	FCNAME=${FCNAME} LIBVER=${LIBVER}

PORTDOCS=	00lastchange README README_libf2c changes f2c.pdf permission

OPTIONS_DEFINE=	DOCS FC LEAD_0
OPTIONS_SUB=	yes

FC_DESC=	f77 script based on f2c
LEAD_0_DESC=	Print with leading zeros
LEAD_0_CFLAGS=	-DWANT_LEAD_0

post-extract:
	cd ${WRKSRC} && ${FIND} . -name "*.gz" | ${XARGS} ${GUNZIP_CMD}
	cd ${WRKSRC} && ${UNZIP_CMD} libf2c.zip
	${CP} -p ${WRKSRC}/libf2c/README ${WRKSRC}/README_libf2c

pre-patch:
	${CP} -p ${WRKSRC}/libf2c/makefile.u ${WRKSRC}/libf2c/Makefile
	${CP} -p ${WRKSRC}/src/makefile.u ${WRKSRC}/src/Makefile

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/fc
	${REINPLACE_CMD} -e 's|#CFLAGS = -O|CFLAGS = ${CFLAGS}|' ${WRKSRC}/src/Makefile
	${REINPLACE_CMD} 's|%%LIBVER%%|${LIBVER}|' ${WRKSRC}/libf2c/Makefile

do-build:
	@${ECHO_MSG} "===> Building f2c..."
	@(cd ${WRKSRC}/src && ${DO_MAKE_BUILD} ${ALL_TARGET})
	@${ECHO_MSG} "===> Building libf2c..."
	@(cd ${WRKSRC}/libf2c && ${DO_MAKE_BUILD} ${ALL_TARGET} libf2c.so)
	${MV} ${WRKSRC}/libf2c/libf2c.so ${WRKSRC}/libf2c/libf2c.so.${LIBVER}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/f2c ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/f2c.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/src/f2c.1t ${STAGEDIR}${MAN1PREFIX}/man/man1/f2c.1
	${INSTALL_DATA} ${WRKSRC}/libf2c/libf2c.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libf2c/libf2c.so.${LIBVER} ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libf2c.so.${LIBVER} ${STAGEDIR}${PREFIX}/lib/libf2c.so

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-install-FC-on:
	${INSTALL_SCRIPT} ${WRKSRC}/fc ${STAGEDIR}${PREFIX}/bin/${FCNAME}

.include <bsd.port.mk>

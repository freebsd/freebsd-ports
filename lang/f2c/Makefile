# Ports collection makefile for:	f2c-freebsd
# Date created:				28 DEC 1998
# Whom:					Steven G. Kargl
#
# $FreeBSD$
#

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

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

GUNZIP_CMD=	minigzip -d
USE_GMAKE=	yes
USE_LDCONFIG=	yes

# Set FCNAME to the name of the Fortran 77 / F2C wrapper.
FCNAME?=	fc
PLIST_SUB=	FCNAME=${FCNAME}
.if defined(WITH_FC)
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
.if defined(WITH_FC)
	${INSTALL_SCRIPT} ${WRKSRC}/fc ${PREFIX}/bin/${FCNAME}
.endif
	${INSTALL_DATA} ${WRKSRC}/src/f2c.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/src/${MAN1}t ${MAN1PREFIX}/man/man1/${MAN1}
	${INSTALL_DATA} ${WRKSRC}/libf2c/libf2c.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libf2c/libf2c.so.2 ${PREFIX}/lib
	${LN} -sf libf2c.so.2 ${PREFIX}/lib/libf2c.so

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>

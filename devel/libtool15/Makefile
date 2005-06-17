# New ports collection makefile for:	libtool
# Date created:		6 May 1998
# Whom:			Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME?=	libtool
PORTVERSION=	1.5.18
PORTREVISION?=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libtool
DISTNAME=	libtool-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org
COMMENT?=	Generic shared library support script (1.5)

BUILD_VERSION=	15
LATEST_LINK?=	libtool${BUILD_VERSION}
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
GNU_CONFIGURE=	 yes
CONFIGURE_ARGS?= --disable-ltdl-install
CONFIGURE_ARGS+= --program-suffix=${BUILD_VERSION}
CONFIGURE_ENV=	PREFIX=${PREFIX} PACKAGE=libtool${BUILD_VERSION}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_REINPLACE=	yes

.if ${PORTNAME} == "libtool"
INFO=		libtool${BUILD_VERSION}
.endif

post-patch:
	@(cd ${WRKSRC}/doc && \
		${RM} -f *.info* && \
		${MV} libtool.texi libtool${BUILD_VERSION}.texi && \
		${REINPLACE_CMD} -E 's,(libtool|libtoolize)\),\1${BUILDVERSION}\),g' libtool${BUILD_VERSION}.texi)
	@${MV} -f ${WRKSRC}/libtool.m4 ${WRKSRC}/libtool${BUILD_VERSION}.m4
	@${MV} -f ${WRKSRC}/ltdl.m4 ${WRKSRC}/ltdl${BUILD_VERSION}.m4
	@${REINPLACE_CMD} -e 's|libtool.m4|libtool${BUILD_VERSION}.m4|g' \
			  -e 's|ltdl.m4|ltdl${BUILD_VERSION}.m4|g' ${WRKSRC}/Makefile.in

.if ${PORTNAME} == "libtool"
post-install:
	@-${RM} -fr ${PREFIX}/libexec/libtool${BUILD_VERSION}
	@${MKDIR} ${PREFIX}/libexec/libtool${BUILD_VERSION}
.for i in libtool libtoolize
	@${LN} -sf ${PREFIX}/bin/${i}${BUILD_VERSION} ${PREFIX}/libexec/libtool${BUILD_VERSION}/${i}
.endfor
.endif

.include <bsd.port.mk>

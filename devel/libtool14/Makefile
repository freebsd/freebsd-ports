# New ports collection makefile for:	libtool
# Date created:		6 May 1998
# Whom:			Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME?=	libtool
PORTVERSION=	1.4.3
PORTREVISION?=	2
CATEGORIES=	devel
#MASTER_SITES=	${MASTER_SITE_GNU}
#MASTER_SITE_SUBDIR=	libtool
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ade/gnu
DISTNAME=	libtool-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org
COMMENT?=	Generic shared library support script

BUILD_VERSION=	14
LATEST_LINK?=	libtool${BUILD_VERSION}
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
GNU_CONFIGURE=	 yes
CONFIGURE_ARGS?= --disable-ltdl-install
CONFIGURE_ARGS+= --program-suffix=${BUILD_VERSION}
CONFIGURE_ENV=	PREFIX=${PREFIX} PACKAGE=libtool${BUILD_VERSION}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_REINPLACE=	yes

.if defined(USE_LIBTOOL) || defined(USE_LIBTOOL_VER)
pre-everything:
	@${ECHO} ===========================================================
	@${ECHO} "You have 'USE_LIBTOOL' or 'USE_LIBTOOL_VER' variables"
	@${ECHO} "defined either in environment or in make(1) arguments."
	@${ECHO} "Please undefine them and try again."
	@${ECHO} ===========================================================
	@${FALSE}
.endif # defined(USE_LIBTOOL) || defined(USE_LIBTOOL_VER)

post-patch:
	@(cd ${WRKSRC}/doc && \
		${RM} -f *.info* && \
		${MV} libtool.texi libtool${BUILD_VERSION}.texi && \
		${REINPLACE_CMD} -E 's,(libtool|libtoolize)\),\1${BUILDVERSION}\),g' libtool${BUILD_VERSION}.texi)
	@${MV} -f ${WRKSRC}/libtool.m4 ${WRKSRC}/libtool${BUILD_VERSION}.m4
	@${MV} -f ${WRKSRC}/ltdl.m4 ${WRKSRC}/ltdl${BUILD_VERSION}.m4
	@${REINPLACE_CMD} -e 's|libtool.m4|libtool${BUILD_VERSION}.m4|g' \
			  -e 's|ltdl.m4|ltdl${BUILD_VERSION}.m4|g' ${WRKSRC}/Makefile.in

post-install:
	@-${RM} -fr ${PREFIX}/libexec/libtool${BUILD_VERSION}
	@${MKDIR} ${PREFIX}/libexec/libtool${BUILD_VERSION}
.for i in libtool libtoolize
	${LN} -sf ${PREFIX}/bin/${i}${BUILD_VERSION} ${PREFIX}/libexec/libtool${BUILD_VERSION}/${i}
.endfor
.for i in config.guess config.sub
	${MV} ${PREFIX}/share/libtool${BUILD_VERSION}/${i}${BUILD_VERSION} ${PREFIX}/share/libtool${BUILD_VERSION}/${i}
.endfor

.include <bsd.port.mk>

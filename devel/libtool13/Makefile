# New ports collection makefile for:	libtool
# Date created:		6 May 1998
# Whom:			Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME=	libtool
PORTVERSION=	1.3.5
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libtool
DISTNAME=	libtool-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org
COMMENT=	Generic shared library support script (1.3)

BUILD_VERSION=	13
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
LATEST_LINK=	libtool${BUILD_VERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-ltdl-install \
		--program-suffix=${BUILD_VERSION}
CONFIGURE_ENV=	PREFIX=${PREFIX} PACKAGE=libtool${BUILD_VERSION}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_REINPLACE=	yes
INFO=		libtool${BUILD_VERSION}

post-patch:
	@(cd ${WRKSRC}/doc && \
		${RM} -f *.info* && \
		${MV} libtool.texi libtool${BUILD_VERSION}.texi && \
		${REINPLACE_CMD} -E 's,(libtool|libtoolize)\),\1${BUILDVERSION}\),g' libtool${BUILD_VERSION}.texi)
	@${MV} -f ${WRKSRC}/libtool.m4 ${WRKSRC}/libtool${BUILD_VERSION}.m4
	@${REINPLACE_CMD} -e 's|libtool.m4|libtool${BUILD_VERSION}.m4|g' ${WRKSRC}/Makefile.in

post-install:
	@-${RM} -fr ${PREFIX}/libexec/libtool${BUILD_VERSION}
	@${MKDIR} ${PREFIX}/libexec/libtool${BUILD_VERSION}
.for i in libtool libtoolize
	@${LN} -sf ${PREFIX}/bin/${i}${BUILD_VERSION} ${PREFIX}/libexec/libtool${BUILD_VERSION}/${i}
.endfor
.for i in config.guess config.sub
	@${MV} ${PREFIX}/share/libtool${BUILD_VERSION}/${i}${BUILD_VERSION} ${PREFIX}/share/libtool${BUILD_VERSION}/${i}
.endfor
	@${LN} -sf ${PREFIX}/share/libtool${BUILD_VERSION}/ltconfig${BUILD_VERSION} \
		${PREFIX}/share/libtool${BUILD_VERSION}/ltconfig

.include <bsd.port.mk>

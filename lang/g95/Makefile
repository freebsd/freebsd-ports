# Ports collection makefile for:  g95
# Date created: 		  2007/01/29
# Whom:				  SATO Hiroki, <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	g95
PORTVERSION=	${G95VERSION}.${SNAPDATE}
CATEGORIES=	lang
MASTER_SITES=	http://ftp.g95.org/v0.9/:g95 \
		${MASTER_SITE_LOCAL}:g95 \
		${MASTER_SITE_GCC:S/$/:gcc/}
MASTER_SITE_SUBDIR=	releases/gcc-${GCC_VER}/:gcc \
			maho/g95/:g95
DISTFILES=	${PORTNAME}_source.tgz:g95 \
		gcc-core-${GCC_VER}${EXTRACT_SUFX}:gcc
DIST_SUBDIR=	g95/${SNAPDATE}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Fortran 95 compiler from g95.org

SNAPDATE=	20070129
G95VERSION=	0.91
WRKSRC=		${WRKDIR}/${PORTNAME}-${G95VERSION}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gcc-dir=${GCC_DIR}
.if !defined(NOPORTDOCS)
CONFIGURE_ENV=	DOCSDIR=${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

GCC_VER=	4.0.3
GCC_DIR=	${WRKDIR}/gcc-${GCC_VER}
GCC_G95_DIR=	${WRKDIR}/gcc-${GCC_VER}/g95
GCC_CONFIGURE_SCRIPT=	../configure
GCC_CONFIGURE_ARGS=	${CONFIGURE_ARGS} --enable-languages=c

post-extract:
	${MKDIR} ${GCC_G95_DIR}
	cd ${WRKSRC} && ${TAR} xzf libf95.a-${G95VERSION}.tar.gz

pre-configure:
	cd ${GCC_G95_DIR} && \
		${GCC_CONFIGURE_SCRIPT} ${GCC_CONFIGURE_ARGS} && \
		${MAKE_ENV} ${GMAKE}

post-build:
	cd ${WRKSRC}/libf95.a-${G95VERSION} && \
		./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} &&\
		${MAKE_ENV} ${GMAKE}

post-install:
	cd ${WRKSRC}/libf95.a-${G95VERSION} && ${GMAKE} ${INSTALL_TARGET}
	cd ${PREFIX}/bin && ${LN} -s -f ${CONFIGURE_TARGET:Q}-g95 g95
	cd ${PREFIX}/bin && ${LN} -s -f ${CONFIGURE_TARGET:Q}-g95 f95
	cd ${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET:Q}/${GCC_VER} && \
		${RM} -f ./${CONFIGURE_TARGET:Q} && \
		${LN} -s -f . ./${CONFIGURE_TARGET:Q}
	${ECHO_CMD} "bin/${CONFIGURE_TARGET:Q}-g95" >> ${TMPPLIST}
	cd ${PREFIX} ; ${FIND} -s lib/gcc-lib/${CONFIGURE_TARGET:Q}/${GCC_VER} -type f  >> ${TMPPLIST}
	cd ${PREFIX} ; ${FIND} -s lib/gcc-lib/${CONFIGURE_TARGET:Q}/${GCC_VER} -type l  >> ${TMPPLIST}
	${ECHO_CMD} "@dirrm lib/gcc-lib/${CONFIGURE_TARGET:Q}/${GCC_VER}" >> ${TMPPLIST}
	${ECHO_CMD} "@dirrm lib/gcc-lib/${CONFIGURE_TARGET:Q}"            >> ${TMPPLIST}
	${ECHO_CMD} "@dirrm lib/gcc-lib"                                  >> ${TMPPLIST}

.include <bsd.port.post.mk>

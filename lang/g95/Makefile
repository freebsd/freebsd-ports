# Ports collection makefile for:  g95
# Date created: 		  2007/01/29
# Whom:				  SATO Hiroki, <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	g95
PORTVERSION=	${G95VERSION}.${SNAPDATE}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}:g95 \
    		http://people.freebsd.org/~gahr/distfiles/:g95 \
		${MASTER_SITE_GCC:S/$/:gcc/}
MASTER_SITE_SUBDIR=	gahr:g95 \
    			releases/gcc-${GCCVERSION}/:gcc
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:g95 \
    		gcc-core-${GCCVERSION}${EXTRACT_SUFX}:gcc

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Fortran 95 compiler from g95.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

SNAPDATE=	20090506
G95VERSION=	0.92
GCCVERSION=	4.0.3
GCCBUILDDIR=	${WRKDIR}/gcc-${GCCVERSION}/
LIBF95=		libf95.a-${G95VERSION}

CONFIGURE_ARGS+=--with-gcc-dir=${GCCBUILDDIR}

PLIST_FILES=	bin/g95 bin/f95 lib/libf95.a
PORTDOCS=	G95Manual.pdf

post-extract:
	cd ${WRKSRC} && ${TAR} xzf ${LIBF95}.tar.gz

pre-configure:
	${MKDIR} ${GCCBUILDDIR}/g95
	cd ${GCCBUILDDIR}/g95 && ../${CONFIGURE_SCRIPT}
	${GMAKE} -C ${GCCBUILDDIR}/g95

post-configure:
	cd ${WRKSRC}/${LIBF95} && ./${CONFIGURE_SCRIPT} \
	    ${CONFIGURE_ARGS}

post-build:
	cd ${WRKSRC}/${LIBF95} && ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/g95 ${PREFIX}/bin
	${LN} -fs ${PREFIX}/bin/g95 ${PREFIX}/bin/f95
	${INSTALL_DATA} ${WRKSRC}/${LIBF95}/libf95.a ${PREFIX}/lib

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

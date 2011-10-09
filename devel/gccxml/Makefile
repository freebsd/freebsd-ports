# New ports collection makefile for:	gccxml
# Date created:			2003-07-16
# Whom:				Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	gccxml
PORTVERSION=	0.6.0
CATEGORIES=	devel
MASTER_SITES=	http://www.gccxml.org/files/v0.6/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML output extension to GCC

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

DEPRECATED=	Unmaintained upstream, still requires GCC 3.4 (strictly), just used by boost-pyste which is of archeological interest only itself
EXPIRATION_DATE=2011-10-13

BROKEN=		does not compile

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-build

MAN1=	gccxml.1

PLIST_SUB=	PORTVERSION=0.6

post-extract:
	${MKDIR} ${WRKSRC}

do-configure:
	${CP} ${TEMPLATES}/config.guess ${WRKSRC}/../gccxml-0.6.0/GCC/
	${CP} ${TEMPLATES}/config.sub ${WRKSRC}/../gccxml-0.6.0/GCC/
	${REINPLACE_CMD} -e "s,x86_64,amd64," \
		${WRKSRC}/../gccxml-0.6.0/GCC/gcc/config.gcc
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} \
	${LOCALBASE}/bin/cmake ../${DISTNAME} -DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
	  -DGCCXML_MAN_DIR:PATH="/man"

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Build fails on powerpc
.elif ${OSVERSION} >= 700042
# GCC-XML has some constructs that GCC 4.2 does not like. Namely,
# the use of casted-pointer-dereferences as an lvalue to post-increment
# operations.
USE_GCC=	3.4
CONFIGURE_ENV+=	CPP="gcc34 -E"
MAKE_ENV+=	CPP="gcc34 -E"
.endif

.if ${OSVERSION} >= 700000
OSMAJOR=${OSREL:C|^([0-9]+)\..*|\1|}
GCC_CONFIG=${PATCH_WRKSRC}/GCC/gcc/config

post-patch:
	${SED} -e "s,MAJOR 6,MAJOR ${OSMAJOR}," \
		${GCC_CONFIG}/freebsd6.h > ${GCC_CONFIG}/freebsd${OSMAJOR}.h
	${REINPLACE_CMD} -e "s,FBSD_MAJOR == 6,FBSD_MAJOR == ${OSMAJOR},g" \
			 -e "s,__FreeBSD__=6,__FreeBSD__=${OSMAJOR},g" \
		${GCC_CONFIG}/freebsd-spec.h
.endif

.include <bsd.port.post.mk>

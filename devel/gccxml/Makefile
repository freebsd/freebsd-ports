# New ports collection makefile for:	gccxml
# Date created:			2003-07-16
# Whom:				Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	gccxml
PORTVERSION=	0.4.2
CATEGORIES=	devel
MASTER_SITES=	http://www.gccxml.org/files/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-cc1plus-304${EXTRACT_SUFX}

MAINTAINER=	stolz@i2.informatik.rwth-aachen.de
COMMENT=	XML output extension to GCC

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

# This one's neat: We have to build things in two subdirectories,
#   but only need to invoke configure in one of them. This means we
#   only have to override the build-stage entirely but can keep the
#   other stages:

CONFIGURE_WRKSRC=	${WRKDIR}/${DISTNAME}-cc1plus-304-build
CONFIGURE_SCRIPT=	../${DISTNAME}-cc1plus-304/configure
INSTALL_WRKSRC=		${WRKDIR}/${DISTNAME}-build

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-languages=c++ --without-libstdcxx -disable-nls --without-libstdc

MAN1=	gccxml.1

PLIST_SUB=	PORTVERSION=${PORTVERSION}

pre-configure:
	${MKDIR} ${CONFIGURE_WRKSRC}
	${MKDIR} ${WRKDIR}/${DISTNAME}-build
	cd ${WRKDIR}/${DISTNAME}-build && \
	${LOCALBASE}/bin/cmake ../${DISTNAME} -DCMAKE_INSTALL_PREFIX:PATH=${PREFIX}

do-build:
	cd ${CONFIGURE_WRKSRC}/libiberty && ${MAKE} libiberty.a
	cd ${CONFIGURE_WRKSRC}/gcc && ${MAKE} tm.h tm_p.h cc1plus
	cd ${WRKDIR}/${DISTNAME}-build && ${MAKE}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Copyright.txt ${DOCSDIR}
.endif
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}-cc1plus-304-build/gcc/cc1plus ${PREFIX}/bin/gccxml_cc1plus

.include <bsd.port.mk>

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

MAINTAINER=	vs@FreeBSD.org
COMMENT=	XML output extension to GCC

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

NOT_FOR_ARCHS=	amd64 sparc64 ia64 # cf. lang/gcc30

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-build

MAN1=	gccxml.1

PLIST_SUB=	PORTVERSION=0.6

post-extract:
	${MKDIR} ${WRKSRC}

do-configure:
	cd ${WRKSRC} && \
	${LOCALBASE}/bin/cmake ../${DISTNAME} -DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
	  -DGCCXML_MAN_DIR:PATH="/man"

.include <bsd.port.mk>

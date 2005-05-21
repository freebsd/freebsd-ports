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

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-build
USE_REINPLACE=	yes

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
	${LOCALBASE}/bin/cmake ../${DISTNAME} -DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
	  -DGCCXML_MAN_DIR:PATH="/man"

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Build fails on alpha"
.endif

.include <bsd.port.post.mk>

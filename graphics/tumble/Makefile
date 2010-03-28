# New ports collection makefile for:	lcdtest
# Date created:				12 Jan 2010
# Whom:					Rob Farmer <rfarmer@predatorlabs.net>
#
# $FreeBSD$
#

PORTNAME=	tumble
PORTVERSION=	0.33
PORTREVISION=	2
CATEGORIES=	graphics print
MASTER_SITES=	http://tumble.brouhaha.com/download/ \
		http://www.predatorlabs.net/dl/

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Creates a PDF file from image files

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		netpbm.1:${PORTSDIR}/graphics/netpbm
BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex

USE_GMAKE=	yes
USE_BISON=	build

MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

ONLY_FOR_ARCHS=	amd64 arm i386 ia64 pc98
ONLY_FOR_ARCHS_REASON=	Only works on little endian systems

PLIST_FILES=	bin/tumble
PORTDOCS=	README

post-patch:
	${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|LDFLAGS =|LDFLAGS= ${LDFLAGS}|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|-lpbm|-lnetpbm|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tumble ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>

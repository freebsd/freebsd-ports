# ex:ts=8
# Ports collection makefile for:	pngwriter
# Date created:			Nov 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pngwriter
PORTVERSION=	0.3.7
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ library for creating PNG images

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_REINPLACE=	yes
ALL_TARGET=	libpngwriter

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/make.include.linux

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/pngwriter.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/libpngwriter.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/*.cc ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

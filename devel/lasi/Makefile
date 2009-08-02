# New ports collection makefile for:	lasi
# Date created:		June 2006
# Whom:			giffunip
#
# $FreeBSD$
#    $MCom: ports/devel/lasi/Makefile,v 1.1 2006/10/04 20:25:40 ahze Exp $

PORTNAME=	lasi
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	libLASi-${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	C++ stream output interface for creating Postscript documents

USE_GNOME=	pango pkgconfig
USE_AUTOTOOLS=	libltdl:22
PKG_CONFIG_PATH=	${PREFIX}/libdata/pkgconfig
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${PKG_CONFIG_PATH}

USE_LDCONFIG=	yes

USE_CMAKE=	yes
CMAKE_ARGS+=	${WRKSRC}	\
		-DCMAKE_INSTALL_PREFIX=${PREFIX}	\
		-DCMAKE_INSTALL_DATADIR:PATH=${DATADIR}

post-install:
	${MV} ${PREFIX}/lib/libLASi.so.0.0.1 ${PREFIX}/lib/libLASi.so.0
.ifdef NOPORTEXAMPLES
	${RM} -rf ${DATADIR}
.else
	${MV} ${DATADIR}/examples ${EXAMPLESDIR}
	${RMDIR} ${DATADIR}
.endif

.include <bsd.port.mk>

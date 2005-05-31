# ex:ts=8
# Ports collection makefile for:	CodeWorker
# Date created:			Dec 31, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	codeworker
PORTVERSION=	3.10.4
CATEGORIES=	devel
MASTER_SITES=	http://codeworker.free.fr/downloads/
DISTNAME=	CodeWorker_SRC${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A parsing tool and a source code generator

EXTRACT_BEFORE_ARGS=	-qo -aa

WRKSRC=		${WRKDIR}/CodeWorker${PORTVERSION:S/./_/g}

USE_ZIP=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CXX}" CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" LFLAGS="-lm"

CFLAGS+=	-Dstricmp=strcasecmp

PLIST_FILES=	bin/codeworker

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
CFLAGS+=	-fpermissive
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/codeworker ${PREFIX}/bin

.include <bsd.port.post.mk>

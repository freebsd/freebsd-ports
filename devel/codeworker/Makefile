# ex:ts=8
# Ports collection makefile for:	CodeWorker
# Date created:			Dec 31, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	codeworker
PORTVERSION=	3.2
CATEGORIES=	devel
MASTER_SITES=	http://codeworker.free.fr/downloads/
DISTNAME=	CodeWorker_SRC${PORTVERSION:S/./_/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A parsing tool and a source code generator

USE_ZIP=	yes
USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes
LDFLAGS+=	-lcompat
USE_GMAKE=	yes
MAKE_ENV=	LDFLAGS="${LDFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e "s|^CXXFLAGS|#CXXFLAGS|g" \
		-e s"|LFLAGS|LDFLAGS|" -e "s|^LDFLAGS|#LDFLAGS|" \
		-e "s|CC|CXX|g" -e "s|^CXX|#CXX|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/CodeWorker ${PREFIX}/bin

.include <bsd.port.mk>

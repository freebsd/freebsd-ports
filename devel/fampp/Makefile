# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	fampp
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ wrapper for fam from SGI

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USES=		fam:fam

NO_STAGE=	yes
do-install:
.for FILE in FamppEvents.hh FamppExceptions.hh fam.hh famStatic.hh handle.hh
	${INSTALL_DATA} ${WRKSRC}/include/${FILE} ${PREFIX}/include
.endfor
	${MKDIR} ${PREFIX}/include/private
	${INSTALL_DATA} ${WRKSRC}/include/private/FamppEventModel.hh \
			${WRKSRC}/include/private/FamppModel.hh ${PREFIX}/include/private
	${MKDIR} ${PREFIX}/share/fampp/examples
.for DIR in gtk simple singleton
	${INSTALL_DATA} ${WRKSRC}/examples/${DIR}/main.cpp ${PREFIX}/share/fampp/examples/${DIR}-main.cpp
.endfor

.include <bsd.port.mk>

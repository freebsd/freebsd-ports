# ports collection makefile for:	fampp
# Date created:				18 March 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	fampp
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ wrapper for fam from SGI

LIB_DEPENDS=	fam.0:${PORTSDIR}/devel/fam

# This isn't required to utilize full functionality
#USE_GNOME=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

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

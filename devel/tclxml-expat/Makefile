# New ports collection makefile for:	tclxml-expat
# Date created:				28 April 2008
# Whom:					Frank Fenor
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-expat

MAINTAINER=	frank@fenor.de

BUILD_DEPENDS=	${LOCALBASE}/lib/TclxmlConfig.sh:${PORTSDIR}/devel/tclxml

USE_LDCONFIG=	${LOCALBASE}/lib/Tclexpat${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/expat
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

MASTERDIR=	${.CURDIR}/../tclxml

BUILDING_EXPAT=	yes
NOPORTDOCS=	yes

.include	"${MASTERDIR}/Makefile"

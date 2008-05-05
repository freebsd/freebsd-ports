# New ports collection makefile for:	tclxml-libxml2
# Date created:				28 April 2008
# Whom:					Frank Fenor
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-libxml2

MAINTAINER=	frank@fenor.de

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=	${LOCALBASE}/lib/TclxmlConfig.sh:${PORTSDIR}/devel/tclxml

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/libxml2
USE_LDCONFIG=	${LOCALBASE}/lib/TclXML_libxml2${PORTVERSION}
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

MASTERDIR=	${.CURDIR}/../tclxml

.include	"${MASTERDIR}/Makefile"
# New ports collection makefile for:	tclxml-libxml2
# Date created:				28 April 2008
# Whom:					Frank Fenor
#
# $FreeBSD$
#

PORTREVISION=	1
PKGNAMESUFFIX=	-libxml2

MAINTAINER=	frank@fenor.de

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=	${LOCALBASE}/lib/TclxmlConfig.sh:${PORTSDIR}/devel/tclxml

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/libxml2
USE_LDCONFIG=	${LOCALBASE}/lib/TclXML_libxml2${PORTVERSION}
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

MASTERDIR=	${.CURDIR}/../tclxml

NOPORTDOCS=	yes

post-build:
	${REINPLACE_CMD} -e 's|@tcldomxml_LIB_FILE@|libTclXML_libxml2${PORTVERSION}.so|' \
	-e 's|@tclxml_libxml2_LIB_SPEC@|${LOCALBASE}/lib/TclXML_libxml2${PORTVERSION}/libTclXML_libxml2${PORTVERSION}.so|' \
	-e 's|@tclxml_libxml2_stub_LIB_FILE@|libTclxmlstub${PORTVERSION}.a|' \
	-e 's|@tclxml_libxml2_STUB_LIB_SPEC@|${LOCALBASE}/lib/Tclxml${PORTVERSION}/libTclxmlstub${PORTVERSION}.a|' \
	-e 's|@tclxml_libxml2_STUB_LIB_PATH@|${LOCALBASE}/lib/TclXML_libxml2${PORTVERSION}|' \
	${WRKSRC}/tcllibxml2Config.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tcllibxml2Config.sh ${LOCALBASE}/lib

.include	"${MASTERDIR}/Makefile"

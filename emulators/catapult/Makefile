# New ports collection makefile for:	emulators/catapult
# Date created:				14 November 2007
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $Carpetsmoker: ports/emulators/catapult/Makefile,v 1.2 2008/07/21 12:54:29 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	catapult
PORTVERSION=	0.8.0
CATEGORIES=	emulators
MASTER_SITES=	SF/openmsx/openmsx/${PORTVERSION}
DISTNAME=	openmsx-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for openMSX

BUILD_DEPENDS=	openmsx:${PORTSDIR}/emulators/openmsx
RUN_DEPENDS=	openmsx:${PORTSDIR}/emulators/openmsx

USE_GNOME=	libxml2
USE_WX=		2.6+
USE_PYTHON_BUILD=yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ARGS=	INSTALL_BASE="${PREFIX}" \
		INSTALL_SHARE_DIR="${DATADIR}" \
		CATAPULT_FLAVOUR="portbld" \
		CATAPULT_OPENMSX_BINARY="${LOCALBASE}/bin/openmsx" \
		CATAPULT_OPENMSX_SHARE="${LOCALBASE}/share/openmsx" \
		SYMLINK_FOR_BINARY="false"

.if defined(NOPORTDOCS)
# Use dummy target rather than rewriting makefile
MAKE_ARGS+=	INSTALL_DOC_DIR="${WRKSRC}/dummy"
.else
MAKE_ARGS+=	INSTALL_DOC_DIR="${DOCSDIR}"
.endif

.if defined(WITH_DEBUG)
CFLAGS+=	-DDEBUG
CATAPULT_STRIP=	false
.else
CFLAGS+=	-DNDEBUG
CATAPULT_STRIP=	true
.endif

post-patch:
	@${REINPLACE_CMD} 's|INSTALL_BASE|INSTALL_SHARE_DIR|' \
		${WRKSRC}/build/info2code.mk
.for file in build/main.mk build/probe.mk
	@${REINPLACE_CMD} 's|@$$(CXX)|$$(CXX)| ; \
		 s|wx-config|${WX_CONFIG}|g' ${WRKSRC}/${file}
.endfor
	@${ECHO_CMD} > ${WRKSRC}/build/flavour-portbld.mk
	@${ECHO_CMD} 'CXXFLAGS+=${CXXFLAGS}' \
		>> ${WRKSRC}/build/flavour-portbld.mk
	@${ECHO_CMD} 'CATAPULT_STRIP:=${CATAPULT_STRIP}' \
		>> ${WRKSRC}/build/flavour-portbld.mk

.include <bsd.port.mk>

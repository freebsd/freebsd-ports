# New ports collection makefile for:	emulators/catapult
# Date created:				14 November 2007
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $Carpetsmoker: ports/emulators/catapult/Makefile,v 1.2 2008/07/21 12:54:29 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	catapult
PORTVERSION=	0.6.3R1
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	SF/openmsx/openmsx/0.6.3
DISTNAME=	openmsx-${PORTNAME}-${PORTVERSION:S/R1/-R1/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for openMSX

BUILD_DEPENDS=	openmsx:${PORTSDIR}/emulators/openmsx
RUN_DEPENDS=	openmsx:${PORTSDIR}/emulators/openmsx

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ARGS+=	INSTALL_BASE=${PREFIX} \
		INSTALL_SHARE_DIR=${DATADIR} \
		INSTALL_DOC_DIR=${DOCSDIR} \
		CATAPULT_OPENMSX_BINARY=${LOCALBASE}/bin/openmsx \
		CATAPULT_OPENMSX_SHARE=${LOCALBASE}/share/openmsx
USE_WX=		2.6
USE_GNOME=	libxml2

post-patch:
	@${REINPLACE_CMD} 's|freebsd5\*|freebsd*|; s|x86_64)|amd64)|;' \
	    ${WRKSRC}/build/detectsys.sh
	@${REINPLACE_CMD} 's|@$$(CXX)|$$(CXX)|' ${WRKSRC}/build/main.mk
	@${REINPLACE_CMD} 's|INSTALL_BASE|INSTALL_SHARE_DIR|' ${WRKSRC}/build/info2code.mk
	@${REINPLACE_CMD} 's|wx-config|${WX_CONFIG}|g' \
		${WRKSRC}/build/main.mk ${WRKSRC}/build/probe.mk
.if defined(NOPORTDOCS)
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/build-main.mk
.endif

.include <bsd.port.mk>

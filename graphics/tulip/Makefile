# ex:ts=8
# Ports collection makefile for:	tulip
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tulip
PORTVERSION=	3.1.2
CATEGORIES=	graphics
MASTER_SITES=	SFP/auber/${PORTNAME}/${PORTNAME}-${PORTVERSION}/:src \
    		http://tulip.labri.fr/userHandbook/:doc
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:src \
    		userManual.pdf:doc
DIST_SUBDIR=	tulip/${PDFUPDATE}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A system dedicated to the visualization of huge graphs

LIB_DEPENDS=	GLEW.1:${PORTSDIR}/graphics/glew \
		freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib moc_build uic_build rcc_build gui opengl xml network \
		designer assistant assistantclient
USE_GL=	glut
USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

PORTDOCS=	userManual.pdf
PDFUPDATE=	1

PLIST_SUB+=	TULIP_VERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-extract:
	@${FIND} ${WRKSRC} -name "moc_*" -delete

post-patch:
	@${REINPLACE_CMD} -e 's|<qdir.h>|<QtCore/qdir.h>|' \
	    ${WRKSRC}/software/tulip/src/Application.cpp
	@${REINPLACE_CMD} -e 's|<qtimer.h>|<QtCore/qtimer.h>|' \
	    ${WRKSRC}/software/tulip/src/main.cpp
	@${REINPLACE_CMD} -e 's|docs||g' ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/userManual.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

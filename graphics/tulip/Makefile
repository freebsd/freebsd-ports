# ex:ts=8
# Ports collection makefile for:	tulip
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tulip
PORTVERSION=	3.4.0
CATEGORIES=	graphics
MASTER_SITES=	SF/auber/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A system dedicated to the visualization of huge graphs

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib moc_build uic_build rcc_build gui opengl xml network \
		designer assistant assistantclient
USE_GL=		glew glut
USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_AUTOTOOLS=	libtool:22

USE_LDCONFIG=	yes

PLIST_SUB+=	TULIP_VERSION=${PORTVERSION} \
		TULIP_VERS=${PORTVERSION:R}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

#post-extract:
#	@${FIND} ${WRKSRC} -name "moc_*" -delete

post-patch:
	@${GREP} -lr '/usr/X11R6/include' ${WRKSRC} | ${XARGS} \
	    ${REINPLACE_CMD} -e 's|/usr/X11R6/include|${LOCALBASE}/include|g'
	@${REINPLACE_CMD} -e 's|<qdir.h>|<QtCore/qdir.h>|' \
	    ${WRKSRC}/software/tulip/src/Application.cpp
	@${REINPLACE_CMD} -e 's|<qtimer.h>|<QtCore/qtimer.h>|;s|<qlocale.h>|<QtCore/qlocale.h>|' \
	    ${WRKSRC}/software/tulip/src/main.cpp
	@${REINPLACE_CMD} -e 's|doxygen||g' \
	    ${WRKSRC}/docs/Makefile.am ${WRKSRC}/docs/Makefile.in
	@${REINPLACE_CMD} -e '534,535d' ${WRKSRC}/docs/doxygen/Makefile.in
	@${REINPLACE_CMD} -e '132,133d' ${WRKSRC}/docs/doxygen/Makefile.am

#	@${REINPLACE_CMD} -e 's|docs||g' ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in

.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}-${PORTVERSION}-html.tar.bz2
PORTDOCS=	*
post-install:
	${INSTALL} -d ${DOCSDIR}
	(cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}-html && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.post.mk>

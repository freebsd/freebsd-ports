# ex:ts=8
# Ports collection makefile for:	meshviewer
# Date created:			Jun 10, 2002
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	meshviewer
PORTVERSION=	0.3.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mview
DISTNAME=	mview-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mesh Viewer

USE_QT_VER=	3
USE_GL=		yes
MAKE_ENV=	MOC="${MOC}" \
		QTCPPFLAGS="${QTCPPFLAGS} ${PTHREAD_CFLAGS}" \
		QTCFGLIBS="${QTCFGLIBS} ${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e \
		's|-I$$(QTDIR)/include|$${QTCPPFLAGS}|g ; \
		 s|-L$$(QTDIR)/lib|$${QTCFGLIBS}|g ; \
		 s|-L/usr/local/lib||g ; \
		 s|-L${X11BASE}/lib||g ; \
		 s|=g\+\+|=$${CXX}|g ; \
		 s|^MOC=|#MOC=|g ; \
		 s|-O2|$${CXXFLAGS}|g ; \
		 s|make |$$(MAKE) |g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|<values\.h>|<climits>|g' ${WRKSRC}/mesh/mesh.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mview ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/Documentation && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>

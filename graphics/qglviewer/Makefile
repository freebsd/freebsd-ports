# ex:ts=8
# New ports collection makefile for:	qglviewer
# Date created:			Dec 18, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qglviewer
PORTVERSION=	1.4
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.gris.uni-tuebingen.de/grisalt/projects/qglviewer/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Use OpenGL to play around with three dimensional scenes

USE_AUTOTOOLS=	libtool:15
USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|-lqt"|-lqt-mt ${PTHREAD_LIBS}"|g ; \
		 s|-lqt -lqgl"|-lqt-mt -lqtgl ${PTHREAD_LIBS}"|g ; \
		 s|/moc|/${MOC:T}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^SUBDIRS =.*$$|SUBDIRS = src include|g ; \
		 s| install-pkgdocDATA||g' ${WRKSRC}/Makefile.in

pre-build:
	-@${RM} ${WRKSRC}/src/QCameraKeyPathEditor.h
	-@${RM} ${WRKSRC}/src/QLightSourceEditor.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.css ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DOCSDIR}/html
.endif

.include <bsd.port.mk>

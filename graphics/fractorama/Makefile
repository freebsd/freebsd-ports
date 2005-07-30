# ex:ts=8
# New ports collection makefile for:	fractorama
# Date created:			Apr 15, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fractorama
PORTVERSION=	1.6.7
CATEGORIES=	graphics
MASTER_SITES=	http://fractorama.com/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fractal generation program

FORBIDDEN=	http://vuxml.FreeBSD.org/pkg-fractorama.html
EXPIRATION_DATE=2005-08-30

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_QT_VER=	3
USE_BISON=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		QTCPPFLAGS="${QTCPPFLAGS} ${PTHREAD_CFLAGS}" \
		QTCFGLIBS="${QTCFGLIBS} ${PTHREAD_LIBS}"
ALL_TARGET=	release

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|gcc|$${CC}|g ; \
		 s|g++|$${CXX}|g ; \
		 s|-L$${QTROOT}/lib -lqt|-lqt-mt $${QTCFGLIBS}|g ; \
		 s|-I$${QTROOT}/include|$${QTCPPFLAGS}|g ; \
		 s|-O2|$${CFLAGS}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../fractorama.exe ${PREFIX}/bin/fractorama
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/../doc && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/../examples && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

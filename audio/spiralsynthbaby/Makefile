# New ports collection makefile for:	spiralsynthbaby
# Date created:				2002-05-23
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	spiralsynthbaby
PORTVERSION=	0.0.2
CATEGORIES=	audio
MASTER_SITES=	http://www.pawfal.org/Software/SpiralLoops/dload/
DISTNAME=	SpiralSynthBaby-${PORTVERSION}

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Synthesizer plugin for SpiralLoops

BROKEN=		"needs fltk 1.0.10"
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2004-06-18

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

GNU_CONFIGURE=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
PLIST=		${WRKSRC}/pkg-plist
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

DOC_FILES=	CHANGES COPYING README

post-patch:
	${MV} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.orig
	${SED} -e 's|-O3|${PTHREAD_CFLAGS}|g ; \
			s|CFLAGS =|CFLAGS +=|g ; \
			s|CXXFLAGS=|CXXFLAGS+=|g ; \
			s|-lm|${PTHREAD_LIBS} -lm|g ; \
			s|/usr/X11R6|${X11BASE}|g' > ${WRKSRC}/Makefile.in \
			< ${WRKSRC}/Makefile.in.orig

pre-install:
	${ECHO_CMD} lib/SpiralSynthBaby.so > ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOC_FILES}
	${ECHO_CMD} share/doc/spiralsynthbaby/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/doc/spiralsynthbaby >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SpiralSynthBaby.so ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

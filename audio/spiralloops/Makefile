# New ports collection makefile for:	spiralloops
# Date created:				2000-12-06
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	spiralloops
PORTVERSION=	2.0.0
CATEGORIES=	audio
MASTER_SITES=	http://www.pawfal.org/SpiralLoops/dload/
DISTNAME=	SpiralLoops-${PORTVERSION}

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

DOCDIR=		share/doc/${PORTNAME}
DOC_FILES=	CHANGES COPYING README
GNU_CONFIGURE=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
PLIST=		${WRKDIR}/pkg-plist
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

post-patch:
	${PERL} -pi -e "s:-ldl::g; s:^CFLAGS:XCFLAGS:g; s:^CXXFLAGS:XCXXFLAGS:g; s:usr/X11R6:${PREFIX}:g" ${WRKSRC}/Makefile.in
	${PERL} -pi -e 's|-O3|${PTHREAD_CFLAGS}|g ; \
			s|CFLAGS =|CFLAGS +=|g ; \
			s|CXXFLAGS=|CXXFLAGS+=|g ; \
			s|-lm|${PTHREAD_LIBS} -lm|g ; \
			s|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/Makefile.in

pre-install:
	${ECHO_CMD} bin/SpiralLoops > ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOC_FILES}
	${ECHO_CMD} ${DOCDIR}/`${BASENAME} ${i}` >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SpiralLoops ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
.include <bsd.port.mk>

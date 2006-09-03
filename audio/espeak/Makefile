# New ports collection makefile for:	espeak
# Date created:		2006-03-25
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	espeak
PORTVERSION=	1.13
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	speak-${PORTVERSION}-source

MAINTAINER=	nivit@email.it
COMMENT=	A software speech synthesizer

LIB_DEPENDS=	portaudio:${PORTSDIR}/audio/portaudio

CONFLICTS=	speak-1.[0-9]

MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" CXX="${CXX}"

USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_ZIP=	yes

WRKSRC=	${WRKDIR}/${DISTNAME}
BUILD_WRKSRC=	${WRKSRC}/src

FIND_DIRS=	espeak-data
FIND_DOCS=	docs

REPLACE_FILES=	 ${BUILD_WRKSRC}/Makefile  ${BUILD_WRKSRC}/speak.cpp

post-patch:
	@for FILE in ${REPLACE_FILES}; do \
	    ${REINPLACE_CMD} \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%DATADIR%%|${DATADIR}|g" $${FILE} ;\
	done;

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/speak ${PREFIX}/bin/speak
	cd ${WRKSRC} && ${FIND} ${FIND_DIRS}  -type d -exec ${MKDIR} \
		${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} ${FIND_DIRS}  -type f -exec ${INSTALL_DATA} {} \
		${DATADIR}/{} \;

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/${FIND_DOCS} && ${FIND} . -type d -exec ${MKDIR} \
		${DOCSDIR}/{} \;
	cd ${WRKSRC}/${FIND_DOCS} && ${FIND} . -type f \
		-exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		requires iswdigit(3)
.endif

.include <bsd.port.post.mk>

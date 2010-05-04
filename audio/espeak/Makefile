# New ports collection makefile for:	espeak
# Date created:		2006-03-25
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	espeak
PORTVERSION=	1.43.03
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A software speech synthesizer

LIB_DEPENDS=	portaudio:${PORTSDIR}/audio/portaudio

CONFLICTS=	speak-1.[0-9]

MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

USE_GMAKE=	yes
USE_GCC=	4.2+
USE_LDCONFIG=	yes
USE_ZIP=	yes

WRKSRC=	${WRKDIR}/${DISTNAME}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src

REINPLACE_FILES=	Makefile speech.h
REINPLACE_ARGS=	-i.bak -e "s|%%DATADIR%%|${DATADIR}|g"

post-patch:
	cd ${BUILD_WRKSRC} && ${REINPLACE_CMD} ${REINPLACE_FILES}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>

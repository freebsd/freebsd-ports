# New ports collection makefile for:	Super Methane Brothers
# Date created:			22 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	super_methane_brothers
PORTVERSION=	1.4.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.methane.fsnet.co.uk/
DISTNAME=	methane
EXTRACT_SUFX=	.tgz

MAINTAINER=	jylefort@brutele.be
COMMENT=	A port of the Amiga platform game of the same name

LIB_DEPENDS=	clanCore.2:${PORTSDIR}/devel/clanlib \
		mikmod:${PORTSDIR}/audio/libmikmod

WRKSRC=		${WRKDIR}/${DISTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/source/linux
MAKEFILE=	makefile

USE_X_PREFIX=	yes
USE_GMAKE=	yes

MAKE_ENV=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
		PTHREAD_LIBS=${PTHREAD_LIBS}

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/methane ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/authors \
		${WRKSRC}/history \
		${WRKSRC}/readme \
		${WRKSRC}/todo \
		${DOCSDIR}
	${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} \
		${WRKSRC}/docs/block.gif \
		${WRKSRC}/docs/bug.gif \
		${WRKSRC}/docs/cookie.gif \
		${WRKSRC}/docs/gamepic.gif \
		${WRKSRC}/docs/gen.gif \
		${WRKSRC}/docs/info.htm \
		${WRKSRC}/docs/mbug.gif \
		${WRKSRC}/docs/potion.gif \
		${WRKSRC}/docs/puff.gif \
		${WRKSRC}/docs/spike.gif \
		${WRKSRC}/docs/spring.gif \
		${WRKSRC}/docs/sucker.gif \
		${WRKSRC}/docs/title.gif \
		${WRKSRC}/docs/turbo.gif \
		${WRKSRC}/docs/whirly.gif \
		${WRKSRC}/docs/zoom.gif \
		${DOCSDIR}/html
.endif

.include <bsd.port.mk>

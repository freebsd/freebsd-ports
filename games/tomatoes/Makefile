# New ports collection makefile for:	tomatoes
# Date created:				2005 07 Feb
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tomatoes
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-linux-src-${PORTVERSION}5${EXTRACT_SUFX} \
		${PORTNAME}-linux-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tomato-smashing, Q-Bert style

LIB_DEPENDS=	mikmod:${PORTSDIR}/audio/libmikmod

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/tomatoes-${PORTVERSION}5
TDATA=		${WRKDIR}/tomatoes-${PORTVERSION}

USE_X_PREFIX=	yes
MAKEFILE=	makefile
USE_GMAKE=	yes
USE_SDL=	mixer image sound

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not build on 4.X
.endif

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}/music
	${INSTALL_DATA} ${TDATA}/config.cfg ${DATADIR}
	${INSTALL_DATA} ${TDATA}/tomatoes.mpk ${DATADIR}
	${INSTALL_DATA} ${TDATA}/music/IHaveNoTomatoes.it ${DATADIR}/music

.include <bsd.port.post.mk>

# New ports collection makefile for:	evolvotron
# Date created:				16 Mar 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$

PORTNAME=	evolvotron
PORTVERSION=	0.0.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	Generative software that evolves images/textures/patterns

WRKSRC=		${WRKDIR}/${PORTNAME}

QTDIR?=		${X11BASE}
USE_QT_VER=	3

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

MAKE_ENV=	QTDIR="${QTDIR}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/evolvotron ${PREFIX}/bin

.include <bsd.port.post.mk>

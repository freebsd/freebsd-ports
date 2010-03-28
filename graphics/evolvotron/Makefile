# New ports collection makefile for:	evolvotron
# Date created:				16 Mar 2003
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$

PORTNAME=	evolvotron
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Generative software that evolves images/textures/patterns

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui moc_build qmake_build xml
USE_PYTHON=	yes
USE_XORG=	x11
GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 28d ${WRKSRC}/libevolvotron/platform_specific.h
	${REINPLACE_CMD} -e 30d ${WRKSRC}/libevolvotron/platform_specific.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/evolvotron/evolvotron ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/evolvotron_mutate/evolvotron_mutate ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/evolvotron_render/evolvotron_render ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/libevolvotron/libevolvotron.a ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/libfunction/libfunction.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/evolvotron.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

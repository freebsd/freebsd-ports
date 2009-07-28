# New ports collection makefile for:	sturmbahnfahrer
# Date created:		07 Sep 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	stormbaancoureur
PORTVERSION=	2.1.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://bram.creative4vision.nl/stormbaancoureur/download/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simulated obstacle course for automobiles

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/lib/libode.a:${PORTSDIR}/devel/ode

USE_GL=		glut

MAKE_ENV=	DATADIR="${DATADIR}"

BUILD_WRKSRC=	${WRKSRC}/src-stormbaancoureur
INSTALL_WRKSRC=	${WRKSRC}/src-stormbaancoureur

PORTDOCS=	README

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|__DATADIR|"${DATADIR}"|' \
		${WRKSRC}/src-stormbaancoureur/main.cxx

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

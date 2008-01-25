# New ports collection makefile for:	sturmbahnfahrer
# Date created:		07 Sep 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	sturmbahnfahrer
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	http://www.stolk.org/sturmbahnfahrer/download/ \
		http://www.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Simulated obstacle course for automobiles

LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut
BUILD_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${X11BASE}/lib/libode.a:${PORTSDIR}/devel/ode

BROKEN=		does not build

USE_GL=		yes

MAKE_ENV=	DATADIR="${DATADIR}"

BUILD_WRKSRC=	${WRKSRC}/src-sturmbahnfahrer
INSTALL_WRKSRC=	${WRKSRC}/src-sturmbahnfahrer

PORTDOCS=	README

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/games/sturmbahnfahrer|${DATADIR}|' \
		${WRKSRC}/src-sturmbahnfahrer/main.cxx

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

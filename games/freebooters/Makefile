# New ports collection makefile for: freebooters
# Date created:		02 July 2004
# Whom:			<janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	freebooters
PORTVERSION=	0.2.1
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/freebooters/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Freebooters is a free clone of the classic Pirates!

BROKEN=		Unfetchable

USE_GMAKE=	yes
USE_SDL=	mixer image sdl ttf
USE_REINPLACE=	yes
DOC_FILES=	AUTHORS COPYING COPYRIGHT NEWS README \
		README_BUCCANEER TODO manual.tex
MAN6=		freebooters.6 buccaneer.6

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on 4.x"
.endif

do-configure:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/sdl_setup.cc
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/tools.cc
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/data/freebooters.conf

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${DOC_FILES} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	fastDNAml
# Date created:		12 Oct 2000
# Whom:	      		Motomichi Matsuzaki <mzaki@e-mail.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	fastdnaml
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://geta.life.uiuc.edu:80/~gary/programs/fastDNAml/
DISTNAME=	fastDNAml_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Faster DNAML, makes phylogenetic trees using maximum likelihood

USE_GMAKE=	yes
do-build:
	@(cd ${WRKSRC}/source; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/fastDNAml ${PREFIX}/bin
	${MKDIR} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/bin/${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	GaUnit
# Date created:                8 May 2004
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$

PORTNAME=	gaunit
PORTVERSION=	0.1.5
CATEGORIES=	devel scheme
MASTER_SITES=	http://www.cozmixng.org/~kou/download/
PKGNAMEPREFIX=	gauche-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An unit testing framework in Gauche

BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes
DOCSDIR=	${PREFIX}/share/doc/gauche/${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/gauche/${PORTNAME}

do-install:
	cd ${WRKSRC}; ${LOCALBASE}/bin/gosh install/install.scm

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} *.en ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} *.ja ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/sample; ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

test:
	cd ${WRKSRC}; ${LOCALBASE}/bin/gosh -I. test/run-test.scm

.include <bsd.port.mk>

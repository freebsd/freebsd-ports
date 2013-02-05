# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	gaunit
PORTVERSION=	0.1.6
CATEGORIES=	devel scheme
MASTER_SITES=	http://www.cozmixng.org/~kou/download/
PKGNAMEPREFIX=	gauche-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An unit testing framework in Gauche

BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
RUN_DEPENDS:=	${BUILD_DEPENDS}

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05
BROKEN=		does not package

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

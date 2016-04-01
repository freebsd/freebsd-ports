# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quickcheck++
PORTVERSION=	0.0.3
CATEGORIES=	devel
MASTER_SITES=	http://software.legiasoft.com/archives/ \
		LOCAL/tota/${PORTNAME}
DISTNAME=	quickcheck_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tool for testing C++ programs automatically, inspired by QuickCheck

LICENSE=	GPLv3

USES=	tar:bzip2

NO_BUILD=	yes

PORTDOCS=	COPYRIGHT README
PORTEXAMPLES=	examples.cc

OPTIONS_DEFINE=	DOCS DOXYGEN
DOXYGEN_DESC=	Build documentation with doxygen

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen:devel/doxygen
PORTDOCS+=	html

pre-install:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/doxygen doxygen.cfg
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/quickcheck
	${INSTALL_DATA} ${WRKSRC}/quickcheck/* ${STAGEDIR}${PREFIX}/include/quickcheck
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in COPYRIGHT README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.if ${PORT_OPTIONS:MDOXYGEN}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

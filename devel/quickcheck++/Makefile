# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quickcheck++
PORTVERSION=	0.0.3
CATEGORIES=	devel
MASTER_SITES=	http://software.legiasoft.com/archives/ \
		LOCAL
MASTER_SITE_SUBDIR=	tota/${PORTNAME}
DISTNAME=	quickcheck_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A tool for testing C++ programs automatically, inspired by QuickCheck

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_BZIP2=	yes

NO_BUILD=	yes

PORTDOCS=	COPYRIGHT README
PORTEXAMPLES=	examples.cc

OPTIONS_DEFINE=	DOXYGEN
DOXYGEN_DESC=	Build documentation with doxygen

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if !defined(NOPORTDOCS) && ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
PORTDOCS+=	html

pre-install:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/doxygen doxygen.cfg
.endif

do-install:
	@${MKDIR} ${PREFIX}/include/quickcheck
	@${INSTALL_DATA} ${WRKSRC}/quickcheck/* ${PREFIX}/include/quickcheck
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in COPYRIGHT README
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.if defined(WITH_DOXYGEN)
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${DOCSDIR}
.endif
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

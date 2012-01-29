# New ports collection makefile for:	quickcheck++
# Date created:		2012-01-29
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quickcheck++
PORTVERSION=	0.0.1
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

OPTIONS=	DOXYGEN "Build documentation with doxygen" off

.include <bsd.port.options.mk>

.if !defined(NOPORTDOCS) && defined(WITH_DOXYGEN)
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

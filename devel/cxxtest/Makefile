# New ports collection makefile for:   cxxtest
# Date created:        14 August 2003
# Whom:                andrew morton
#
# $FreeBSD$
#

PORTNAME=	cxxtest
PORTVERSION=	3.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	drewish@katherinehouse.com
COMMENT=	A simple yet powerful JUnit/CppUnit/xUnit-like framework for C++

WRKSRC=		${WRKDIR}/${PORTNAME}
EXTRACT_SUFX =	.tgz
NO_BUILD=	yes
USE_PERL5_RUN=	yes

do-install:
# scripts
	@${MKDIR} ${PREFIX}/include/cxxtest
	${INSTALL_DATA} ${WRKSRC}/cxxtest/* ${PREFIX}/include/cxxtest/
	${INSTALL_SCRIPT} ${WRKSRC}/cxxtestgen.pl ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/cxxtestgen.py ${PREFIX}/bin/

# docs and examples (minus the win ddk stuff)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/sample
	@${MKDIR} ${DOCSDIR}/test
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.png ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/*.h ${DOCSDIR}/sample/
	${INSTALL_DATA} ${WRKSRC}/sample/*.cpp ${DOCSDIR}/sample/
	${INSTALL_DATA} ${WRKSRC}/sample/*.tpl ${DOCSDIR}/sample/
	${INSTALL_DATA} ${WRKSRC}/sample/Construct ${DOCSDIR}/sample/
	${INSTALL_DATA} ${WRKSRC}/sample/Makefile.unix ${DOCSDIR}/sample/Makefile
	${INSTALL_DATA} ${WRKSRC}/test/*.h ${DOCSDIR}/test/
	${INSTALL_DATA} ${WRKSRC}/test/*.cpp ${DOCSDIR}/test/
	${INSTALL_DATA} ${WRKSRC}/test/*.tpl ${DOCSDIR}/test/
	${INSTALL_DATA} ${WRKSRC}/test/*.out ${DOCSDIR}/test/
	${INSTALL_DATA} ${WRKSRC}/test/test.pl ${DOCSDIR}/test/
	@${ECHO_CMD} "* Documentation and samples have been installed in ${DOCSDIR}"
	@${ECHO_CMD} "* NOTE: the makefiles provided with the samples aren't compatible with FreeBSD's make, use ${GMAKE} instead."
.endif

.include <bsd.port.mk>

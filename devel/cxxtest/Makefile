# New ports collection makefile for:   cxxtest
# Date created:        14 August 2003
# Whom:                andrew morton
#
# $FreeBSD$
#

PORTNAME=	cxxtest
PORTVERSION=	3.9.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	drewish@katherinehouse.com
COMMENT=	Simple and powerful JUnit/CppUnit/xUnit-like framework for C++

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USE_PERL5_RUN=	yes

DOCS=		README TODO docs/*.html docs/*.png
EXAMPLES=	sample/*.cpp sample/*.h sample/*.tpl sample/Construct \
		sample/Makefile.unix sample/gui/GreenYellowRed.h

do-install:
# scripts
	@${MKDIR} ${PREFIX}/include/cxxtest
	${INSTALL_DATA} ${WRKSRC}/cxxtest/* ${PREFIX}/include/cxxtest/
	${INSTALL_SCRIPT} ${WRKSRC}/cxxtestgen.pl ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/cxxtestgen.py ${PREFIX}/bin/
# docs and examples (minus the win ddk stuff)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	@${ECHO_MSG} "* Documentation has been installed in ${DOCSDIR}"
.endif
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
	@${ECHO_MSG} "* Samples have been installed in ${EXAMPLESDIR}"
	@${ECHO_MSG} "* The CxxTest scripts have been installed into ${PREFIX}/bin/."
	@${ECHO_MSG} "* The include files are in ${PREFIX}/include/cxxtest/"
	@${ECHO_MSG} "* Beware that the sample makefiles aren't compatible with FreeBSD's make,"
	@${ECHO_MSG} "* use ${GMAKE} instead."
	@${ECHO_MSG} "* The obvious reminder: don't forget to add ${PREFIX}/include to your include path."

.include <bsd.port.mk>

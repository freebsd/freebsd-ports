# Created by: andrew morton
# $FreeBSD$

PORTNAME=	cxxtest
PORTVERSION=	3.10.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	drewish@katherinehouse.com
COMMENT=	Simple and powerful JUnit/CppUnit/xUnit-like framework for C++

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USES=		gmake perl5 python:2.7,run shebangfix
USE_PERL5=	run
SHEBANG_FILES=	cxxtestgen.pl cxxtestgen.py

DOCS=		README TODO docs/*.html docs/*.png
EXAMPLES=	sample/*.cpp sample/*.h sample/*.tpl sample/Construct \
		sample/Makefile.unix sample/gui/GreenYellowRed.h

do-install:
# scripts
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/cxxtest
	${INSTALL_DATA} ${WRKSRC}/cxxtest/* ${STAGEDIR}${PREFIX}/include/cxxtest/
	${INSTALL_SCRIPT} ${WRKSRC}/cxxtestgen.pl ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/cxxtestgen.py ${STAGEDIR}${PREFIX}/bin/
# docs and examples (minus the win ddk stuff)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
	@@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
	@${ECHO_MSG} "* Samples have been installed in ${EXAMPLESDIR}"
	@${ECHO_MSG} "* The CxxTest scripts have been installed into ${PREFIX}/bin/."
	@${ECHO_MSG} "* The include files are in ${PREFIX}/include/cxxtest/"
	@${ECHO_MSG} "* Beware that the sample makefiles aren't compatible with FreeBSD's make,"
	@${ECHO_MSG} "* use gmake instead."
	@${ECHO_MSG} "* The obvious reminder: don't forget to add ${PREFIX}/include to your include path."

.include <bsd.port.mk>

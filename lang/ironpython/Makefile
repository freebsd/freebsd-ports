# $FreeBSD$

PORTNAME=	ironpython
PORTVERSION=	2.7.3
CATEGORIES=	lang python
DISTNAME=	ipy-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Python implementation based on .NET

LICENSE=	AL2

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

USE_GITHUB=	yes
GH_ACCOUNT=	IronLanguages
GH_PROJECT=	main
GH_TAGNAME=	ipy-2.7.3
GH_COMMIT=	2ae9aee

SUB_FILES=	ipy ipy64

do-build:
	cd ${WRKSRC} && ${LOCALBASE}/bin/xbuild /t:Stage \
		/p:Configuration=Release /p:ReferencedPlatform=V4 \
		/p:Mono=true /p:BaseConfiguration=Release

do-install:
	@${MKDIR} ${PREFIX}/lib/ironpython
	cd ${WRKSRC}/Stage/Release/IronPython-${PORTVERSION} && \
		${COPYTREE_SHARE} . ${PREFIX}/lib/ironpython;
	${CHMOD} a+x ${PREFIX}/lib/ironpython/ipy.exe
	${CHMOD} a+x ${PREFIX}/lib/ironpython/ipy64.exe
	for f in ${SUB_FILES}; do \
		${INSTALL_SCRIPT} ${WRKDIR}/$$f ${PREFIX}/bin; \
	done

post-install:
	@for f in ${SUB_FILES}; do \
		${ECHO_CMD} "bin/$$f" >> ${TMPPLIST}; \
	done
	@${ECHO_CMD} "bin/
	@${FIND} -P ${PREFIX}/lib/ironpython ! -type d 2>/dev/null | \
		${SED} -ne 's,^${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -P -d ${PREFIX}/lib/ironpython -type d 2>/dev/null | \
		${SED} -ne 's,^${PREFIX}/,@dirrm ,p' >> ${TMPPLIST}

.include <bsd.port.mk>

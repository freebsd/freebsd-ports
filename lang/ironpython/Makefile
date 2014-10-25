# $FreeBSD$

PORTNAME=	ironpython
PORTVERSION=	2.7.4
CATEGORIES=	lang python
DISTNAME=	ipy-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Python implementation based on .NET

LICENSE=	APACHE20

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

USE_GITHUB=	yes
GH_ACCOUNT=	IronLanguages
GH_PROJECT=	main
GH_TAGNAME=	ipy-2.7.4
GH_COMMIT=	568c234

SUB_FILES=	ipy ipy64

BROKEN=		does not build with mono 3.4.0
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-11-26

do-build:
	cd ${WRKSRC} && ${LOCALBASE}/bin/xbuild /t:Stage \
		/p:Configuration=Release /p:ReferencedPlatform=V4 \
		/p:Mono=true /p:BaseConfiguration=Release

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ironpython
	cd ${WRKSRC}/Stage/Release/IronPython-${PORTVERSION} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/ironpython;
	${CHMOD} a+x ${STAGEDIR}${PREFIX}/lib/ironpython/ipy.exe
	${CHMOD} a+x ${STAGEDIR}${PREFIX}/lib/ironpython/ipy64.exe
	for f in ${SUB_FILES}; do \
		${INSTALL_SCRIPT} ${WRKDIR}/$$f ${STAGEDIR}${PREFIX}/bin; \
	done

post-install:
	@for f in ${SUB_FILES}; do \
		${ECHO_CMD} "bin/$$f" >> ${TMPPLIST}; \
	done
	@${FIND} -P ${STAGEDIR}${PREFIX}/lib/ironpython ! -type d 2>/dev/null | \
		${SED} -ne 's,^${STAGEDIR}${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -P -d ${STAGEDIR}${PREFIX}/lib/ironpython -type d 2>/dev/null | \
		${SED} -ne 's,^${STAGEDIR}${PREFIX}/,@dirrm ,p' >> ${TMPPLIST}

.include <bsd.port.mk>

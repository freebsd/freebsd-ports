# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	libboard
DISTVERSION=	0.9.4
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Vector graphics C++ library

LICENSE=	LGPL3

LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick

HAS_CONFIGURE=	yes
CXXFLAGS+=	-D_GLIBCXX_USE_C99 # XXX ports/193528
CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ENV=	CXX=${CXX}

USES=		gmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	c-koi
GH_TAGNAME=	5b38274

PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN EXAMPLES
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

.include <bsd.port.pre.mk>

.if ${ARCH} != i386
CXXFLAGS+=	-fPIC
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|-O3|${CXXFLAGS}|;s|g++|${CXX}|'	\
		${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/lib/libboard.so ${STAGEDIR}${PREFIX}/lib/libboard.so.0
	${LN} -sf libboard.so.0 ${STAGEDIR}${PREFIX}/lib/libboard.so

post-install-DOXYGEN-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/
	${RM} -r ${STAGEDIR}${DOCSDIR}/.svn

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/bin/ && ${COPYTREE_BIN} . ${STAGEDIR}${EXAMPLESDIR}/
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}/.svn

do-test:
	(cd ${WRKDIR} && ${WRKSRC}/bin/arithmetic bec)
.for ex in 1 2 3
	(cd ${WRKDIR} && ${WRKSRC}/bin/example${ex})
.endfor
	${LS} -l ${WRKDIR}/arithm* ${WRKDIR}/example*

.include <bsd.port.post.mk>

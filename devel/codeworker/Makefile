PORTNAME=	codeworker
PORTVERSION=	4.5.3
CATEGORIES=	devel
MASTER_SITES=	http://codeworker.free.fr/downloads/
DISTNAME=	CodeWorker_SRC${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Versatile parsing tool and source code generator
WWW=		http://codeworker.free.fr/

LICENSE=	LGPL21

WRKSRC=		${WRKDIR}/CodeWorker${PORTVERSION:S/./_/g}

USES=		dos2unix gmake zip
USE_CXXSTD=	c++14
MAKE_ARGS=	CC="${CXX}" CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" LFLAGS="-lm"
ALL_TARGET=	build

CFLAGS+=	-Dstricmp=strcasecmp

PLIST_FILES=	bin/codeworker

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=dynamic-exception-spec
CPPFLAGS+=	-Wno-error=dynamic-exception-spec
CXXFLAGS+=	-Wno-error=dynamic-exception-spec
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.cpp" -or -name "*.h" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|<features.h>|<cstdio>| ; \
		 s|(__cplusplus) \&\&|(__cplusplus) // \&\&|'
.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
	@${REINPLACE_CMD} -e 's|auto_ptr|unique_ptr|g' \
		${WRKSRC}/CppParsingTree.cpp \
		${WRKSRC}/CppParsingTree.h
	@${REINPLACE_CMD} -E 's|throw\(UtlException\)|noexcept\(false\)|g' \
		${WRKSRC}/CGRuntime.cpp \
		${WRKSRC}/CGRuntime.h
.endif

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} codeworker ${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>

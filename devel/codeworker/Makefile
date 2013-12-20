# Created by: ijliao
# $FreeBSD$

PORTNAME=	codeworker
PORTVERSION=	4.5.3
CATEGORIES=	devel
MASTER_SITES=	http://codeworker.free.fr/downloads/
DISTNAME=	CodeWorker_SRC${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Versatile parsing tool and source code generator

LICENSE=	LGPL21

WRKSRC=		${WRKDIR}/CodeWorker${PORTVERSION:S/./_/g}

USES=		dos2unix gmake
MAKE_ARGS=	CC="${CXX}" CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" LFLAGS="-lm"
ALL_TARGET=	build

CFLAGS+=	-Dstricmp=strcasecmp

PLIST_FILES=	bin/codeworker

post-patch:
	@${FIND} ${WRKSRC} -name "*.cpp" -or -name "*.h" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|<features.h>|<cstdio>| ; \
		 s|(__cplusplus) \&\&|(__cplusplus) // \&\&|'

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} codeworker ${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>

PORTNAME=	asmc
PORTVERSION=	2.37.84
CATEGORIES=	lang devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Masm compatible assembler

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	written in x86 assembly

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	nidud
GH_TAGNAME=	0c144a031b7c8ff335ee41b1eff1b4de353bf4ce

MAKEFILE=	makefile
MAKE_ARGS_i386=	x86=1
MAKE_ARGS+=	${MAKE_ARGS_${ARCH}} \
		SUBVERSION=${PORTVERSION:E}
MAKE_JOBS_UNSAFE=	yes
.if defined(WITH_DEBUG)
MAKE_ARGS+=	debug=1
.endif
ALL_TARGET=	${PROG}

BUILD_WRKSRC=	${WRKSRC}/source/asmc

PROG=		${PROG_${ARCH}}
PROG_amd64=	asmc64
PROG_i386=	asmc

# bootstrap tool
post-extract:
	${CHMOD} +x ${WRKSRC}/bin/${PROG}

post-patch:
	${REINPLACE_CMD} -e 's,/usr/lib/asmc,${PREFIX}/libdata/asmc,' ${BUILD_WRKSRC}/asmc-profile.sh

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PROG} ${STAGEDIR}${PREFIX}/bin/asmc
	${MKDIR} ${STAGEDIR}${PREFIX}/libdata/asmc/include ${STAGEDIR}${PREFIX}/etc/profile.d
	(cd ${WRKSRC} && ${COPYTREE_SHARE} include ${STAGEDIR}${PREFIX}/libdata/asmc/)
	${INSTALL_SCRIPT} ${BUILD_WRKSRC}/asmc-profile.sh ${STAGEDIR}${PREFIX}/etc/profile.d/

.include <bsd.port.mk>

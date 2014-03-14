# Created by: UMENO Takashi
# $FreeBSD$

PORTNAME=	pykawari
PORTVERSION=	8.2.8
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/kawari/kawari/${PORTVERSION}
DISTNAME=	kawari-${PORTVERSION:S/.//g}

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	A real kawari8 module for ninix-aya

EXTRACT_DEPENDS=${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	ninix:${PORTSDIR}/games/ninix-aya

EXTRACT_CMD=	${UNZIP_CMD}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty

PLIST_SUB=	LOCALBASE=${LOCALBASE}

USES=		gmake zip:infozip
USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/kawari-${PORTVERSION:S/.//g}
CFLAGS+=	${PTHREAD_CFLAGS} -fPIC

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|shell python|shell ${PYTHON_CMD}|' \
		${WRKSRC}/build/src/gcc.mak

do-build:
	(cd ${WRKSRC}/build/src; CFLAGS="${CFLAGS}" ${GMAKE} -f gcc.mak PYTHONBASE=${PYTHONBASE} PYTHON_VERSION=${PYTHON_VERSION} PTHREAD_LIBS=${PTHREAD_LIBS} CXX=${CXX})

do-install:
	${MKDIR} ${PREFIX}/share/kawari
	(cd ${WRKSRC}; ${TAR} -cf - document license.txt readme.1st build/BUILD.TXT) | ${TAR} -xvpf - -C ${PREFIX}/share/kawari
	${LN} -f ${WRKSRC}/build/mach/freebsd/libshiori.so ${WRKSRC}/build/mach/freebsd/_kawari8.so
	${MKDIR} ${PREFIX}/libexec/ninix
	${INSTALL_PROGRAM} ${WRKSRC}/build/mach/freebsd/_kawari8.so ${PREFIX}/libexec/ninix

.include <bsd.port.post.mk>

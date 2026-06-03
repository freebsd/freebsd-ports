PORTNAME=	virtual_oss_sndio
DISTVERSION=	${OSVERSION}
CATEGORIES=	audio
DISTFILES=

MAINTAINER=	christos@FreeBSD.org
COMMENT=	virtual_oss sndio backend
WWW=		https://freebsd.org

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libsndio.so:audio/sndio

USES=		pathfix uidfix
USE_LDCONFIG=	yes

MAKE_ENV=	LIBDIR=${PREFIX}/lib \
		MAKEOBJDIRPREFIX=${WRKDIR}

WRKSRC=		${SRC_BASE}/lib/virtual_oss/sndio

PLIST_FILES=	lib/virtual_oss/voss_sndio.so

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/virtual_oss

.include <bsd.port.pre.mk>

.if !exists(${WRKSRC})
IGNORE=		requires FreeBSD source files in ${SRC_BASE}
.endif

.include <bsd.port.post.mk>

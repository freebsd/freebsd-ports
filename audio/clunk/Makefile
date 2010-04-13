# New ports collection makefile for:	clunk
# Date created:		05 Aug 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clunk
DISTVERSION=	r20100412
CATEGORIES=	audio
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Real-time 3D sound generation library

USE_BZIP2=	yes
USE_SDL=	sdl
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

USE_SCONS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	SIMD "Enable SIMD support (SSE)" off

.include <bsd.port.options.mk>

.if !defined(WITH_SIMD)
post-patch:
	@${REINPLACE_CMD} -e '/^have_sse/ s|True|False|' ${WRKSRC}/SConstruct
.endif

.if ${OSVERSION} < 700000
BROKEN=		Requires posix_memalign()
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libclunk.so ${PREFIX}/lib/
	${MKDIR} ${PREFIX}/include/clunk
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/clunk/

.include <bsd.port.mk>

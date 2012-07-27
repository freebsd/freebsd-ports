# New ports collection makefile for:	fraqtive
# Date created:				Wed Sep  7 22:29:05 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fraqtive
PORTVERSION=	0.4.5
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/fraqtive/Fraqtive/Fraqtive%20${PORTVERSION}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Draws Mandelbrot and Julia fractals

USE_BZIP2=	yes
USE_QT4=	gui opengl qmake_build uic_build moc_build rcc_build
QT_NONSTANDARD=	yes
USE_GL=		glu
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	QMAKESPEC="${QMAKESPEC}" \
		QMAKE_CFLAGS="${CFLAGS}"
CONFIGURE_ARGS=	-prefix ${PREFIX} -qmake ${QMAKE}
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	SSE2
SSE2_DESC=	Enable SSE2 optimization

STRIP_FILES=	bin/fraqtive

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MSSE2}
CONFIGURE_ARGS+=-no-sse2
.endif

post-configure:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^CC .*|CC=${CC}|; s|^CXX .*|CXX=${CXX}|' \
		-e 's|^LINK .*|LINK=${CXX}|' \
		-e 's|^CFLAGS .*|CFLAGS=${CFLAGS} -Wall -W $$\(DEFINES\)|' \
		-e 's|^CXXFLAGS .*|CXXFLAGS=${CXXFLAGS} -Wall -W $$\(DEFINES\)|'

post-install:
		${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}

.include <bsd.port.mk>

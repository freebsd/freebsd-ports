# New ports collection makefile for:	fraqtive
# Date created:				Wed Sep  7 22:29:05 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fraqtive
PORTVERSION=	0.4.4
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	makc@issp.ac.ru
COMMENT=	Draws Mandelbrot and Julia fractals

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui opengl qmake_build uic_build moc_build rcc_build
QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	QMAKESPEC="${QMAKESPEC}" \
		QMAKE_CFLAGS="${CFLAGS}"
CONFIGURE_ARGS=	-prefix ${PREFIX} -qmake ${QMAKE}

OPTIONS=	SSE2 "Enable SSE2 optimization" off

INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.if !defined(WITH_SSE2)
CONFIGURE_ARGS+=-no-sse2
.endif

post-configure:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^CC .*|CC=${CC}|; s|^CXX .*|CXX=${CXX}|' \
		-e 's|^LINK .*|LINK=${CXX}|' \
		-e 's|^CFLAGS .*|CFLAGS=${CFLAGS} -Wall -W $$\(DEFINES\)|' \
		-e 's|^CXXFLAGS .*|CXXFLAGS=${CXXFLAGS} -Wall -W $$\(DEFINES\)|'

.include <bsd.port.post.mk>

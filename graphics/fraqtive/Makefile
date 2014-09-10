# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fraqtive
PORTVERSION=	0.4.6
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/fraqtive/Fraqtive/Fraqtive%20${PORTVERSION}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Draws Mandelbrot and Julia fractals

USES=		tar:bzip2
USE_QT4=	gui opengl xml qmake_build uic_build moc_build rcc_build
QT_NONSTANDARD=	yes
USE_GL=		glu
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	QMAKESPEC="${QMAKESPEC}" \
		QMAKE_CFLAGS="${CFLAGS}"
CONFIGURE_ARGS=	-prefix ${PREFIX} -qmake ${QMAKE}
DESTDIRNAME=	INSTALL_ROOT

OPTIONS_DEFINE=	SSE2
SSE2_DESC=	Enable SSE2 optimization
SSE2_CONFIGURE_OFF=	-no-sse2

STRIP_FILES=	bin/fraqtive

post-install:
		${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}

.include <bsd.port.mk>

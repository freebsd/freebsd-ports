# New ports collection makefile for:	adonthell
# Date created:		Sat May 10 15:26:09 CEST 2003
# Whom:			Miguel Mendez <flynn@energyhq.es.eu.org>
#
# $FreeBSD$
#

PORTNAME=	adonthell
PORTVERSION=	0.3.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-src-${PORTVERSION}a${EXTRACT_SUFX} \
	   	wastesedge-src-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	A free role playing game

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13 \
		freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis

USE_SDL=	mixer sdl
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-py-debug
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	LDFLAGS=-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

post-extract:
.for f in configure src/fileops.cc src/gametime.cc src/image.cc src/win_types.h
	@${REINPLACE_CMD} -e 's@SDL/SDL@SDL11/SDL@g' ${WRKSRC}/$f
.endfor

post-install:
	cd ${WRKDIR}/wastesedge-${PORTVERSION} && \
	${REINPLACE_CMD} -e 's/test $$adonthell_major_ver -eq 0 .*/true ;/' configure
	cd ${WRKDIR}/wastesedge-${PORTVERSION} && \
	${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS} \
	--with-adonthell-binary=${PREFIX}/bin/${PORTNAME} \
	${CONFIGURE_TARGET}
	cd ${WRKDIR}/wastesedge-${PORTVERSION} && ${GMAKE}
	cd ${WRKDIR}/wastesedge-${PORTVERSION} && ${GMAKE} install

.include <bsd.port.post.mk>

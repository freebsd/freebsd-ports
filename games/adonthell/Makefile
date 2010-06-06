# New ports collection makefile for:	adonthell
# Date created:		Sat May 10 15:26:09 CEST 2003
# Whom:			Miguel Mendez <flynn@energyhq.es.eu.org>
#
# $FreeBSD$
#    $MCom: ports/games/adonthell/Makefile,v 1.1 2006/10/04 20:13:33 ahze Exp $

PORTNAME=	adonthell
PORTVERSION=	0.3.5
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SAVANNAH
DISTFILES=	${PORTNAME}-src-${PORTVERSION}${EXTRACT_SUFX} \
	   	wastesedge-src-${WEDGE_VERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free role playing game

LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		freetype.9:${PORTSDIR}/print/freetype2

USE_SDL=	mixer ttf sdl
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		PYPACKAGE="${PYTHON_CMD}" ac_cv_path_P_SWIG=no
CONFIGURE_ARGS=	--disable-py-debug

PLIST_SUB=	VERSION="${PORTVERSION:R}"

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

WEDGE_VERSION=	0.3.4

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not build on sparc64
.endif

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e \
		's|-g -Wall|$$CFLAGS -Wall|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' configure
	@cd ${WRKDIR}/wastesedge-${WEDGE_VERSION} && ${REINPLACE_CMD} -e \
		's/test $$adonthell_major_ver -eq 0 .*/true ;/' configure
	@cd ${WRKDIR}/wastesedge-${WEDGE_VERSION} && ${REINPLACE_CMD} -e \
		's/^[[:space:]]*_//' scripts/modules/player_text.py

post-install:
	cd ${WRKDIR}/wastesedge-${WEDGE_VERSION} \
		&& ${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS} \
			--with-adonthell-binary=${PREFIX}/bin/${PORTNAME} \
			${CONFIGURE_TARGET}
	cd ${WRKDIR}/wastesedge-${WEDGE_VERSION} && ${GMAKE}
	cd ${WRKDIR}/wastesedge-${WEDGE_VERSION} && ${GMAKE} install

.include <bsd.port.post.mk>

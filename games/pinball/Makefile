# New ports collection makefile for:	pinball
# Date created:		Tue 13 aug 2002 22:46:02 CEST
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	pinball
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@pompo.net
COMMENT=	Emilia Pinball is a free pinball game

.if !defined(WITH_ALLEGRO)
BUILD_DEPENDS=	${SDL_CONFIG}:${PORTSDIR}/devel/sdl12
.else
BROKEN=		"support with Allegro is (temporarily) broken as of version 0.31"
BUILD_DEPENDS=	${ALLEGRO_CONFIG}:${PORTSDIR}/devel/allegro
LIB_DEPENDS=	alleg.41:${PORTSDIR}/devel/allegro
.endif

USE_SDL=	image mixer sdl
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_MESA=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX} --without-debug
.if defined(WITH_ALLEGRO)
CONFIGURE_ARGS+=	--with-allegro
EXTRA_LIBS=	-lGL -lGLU
.endif
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include -DRZR_LIBSTATIC" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -L${X11BASE}/lib ${EXTRA_LIBS}"
ALLEGRO_CONFIG=	${LOCALBASE}/bin/allegro-config

DOCS=		README

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Configure fails"
.endif

post-install:
	@${MV} ${PREFIX}/bin/${MACHINE_ARCH}-unknown-freebsd${OSREL}-pinball \
		${PREFIX}/bin/pinball
	@${MV} ${PREFIX}/bin/${MACHINE_ARCH}-unknown-freebsd${OSREL}-pinball-config \
		${PREFIX}/bin/pinball-config
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===>   Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>

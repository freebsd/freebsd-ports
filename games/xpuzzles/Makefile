PORTNAME=	xpuzzles
PORTVERSION=	8.9.4
PORTREVISION=	0
CATEGORIES=	games
MASTER_SITES=	https://www.sillycycle.com/puzzles/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Collection of puzzles for X
WWW=		https://www.sillycycle.com/puzzles.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/rubik/COPYING

LIB_DEPENDS=	libXaw3d.so:x11-toolkits/libXaw3d
RUN_DEPENDS=	aplay:audio/alsa-utils

USES=		tar:xz xorg gl localbase desktop-file-utils
USE_GL=		gl glu
USE_XORG=	xt sm ice xext x11 xmu xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-def-play=aplay

XPUZZLES=	rubik skewb dino bevel pyraminx oct mball \
		cubes triangles hexagons panex mlink barrel

pre-configure:
.for dir in ${XPUZZLES}
	${REINPLACE_CMD} \
		-e 's|^#prefix = @prefix@|prefix = @prefix@|' \
		-e 's|^prefix = /usr$$|#prefix = /usr|' \
		-e 's|^gamesdir = /usr/games|gamesdir = @bindir@|' \
		-e 's|^#xapploaddir = @libdir@/X11/app-defaults|xapploaddir = @libdir@/X11/app-defaults|' \
		-e 's|^xapploaddir = /etc/X11/app-defaults|#xapploaddir = /etc/X11/app-defaults|' \
		-e 's|chmod 775 .(scoredir)|chmod 775 \$$\(DESTDIR\)\$$\(scoredir\)|' \
		-e 's|.(INSTALL_PROGRAM) .(srcdir)/.(NAME).scores|\$$\(INSTALL_DATA\) \$$\(srcdir\)/\$$\(NAME\).scores|' \
		-e "s|sed 's;.READ_PATH;.(DESTDIR)|sed 's;.READ_PATH;|" \
		${CONFIGURE_WRKSRC}/${dir}/Makefile.in
.endfor

do-configure:
.for dir in ${XPUZZLES}
	@CONFIG_GUESS_DIRS=$$(${FIND} ${WRKDIR} -name config.guess -o -name config.sub \
		| ${XARGS} -n 1 ${DIRNAME}); \
	for _D in $${CONFIG_GUESS_DIRS}; do \
		${RM} $${_D}/config.guess; \
		${CP} ${TEMPLATES}/config.guess $${_D}/config.guess; \
		${CHMOD} a+rx $${_D}/config.guess; \
		${RM} $${_D}/config.sub; \
		${CP} ${TEMPLATES}/config.sub $${_D}/config.sub; \
		${CHMOD} a+rx $${_D}/config.sub; \
	done
	@${MKDIR} ${CONFIGURE_WRKSRC}/${dir}
	@(cd ${CONFIGURE_WRKSRC}/${dir} && \
	    ${SET_LATE_CONFIGURE_ARGS} \
		if ! ${SETENVI} ${WRK_ENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    LDFLAGS="${LDFLAGS}" LIBS="${LIBS}" \
	    INSTALL="/usr/bin/install -c" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_LIB="${INSTALL_LIB}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS}; then \
			 ${ECHO_MSG} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
			 (${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT_80} ; \
			 ${FALSE}; \
		fi)
.endfor

do-build:
.for dir in ${XPUZZLES}
	@(cd ${BUILD_WRKSRC}/${dir}; if ! ${DO_MAKE_BUILD} ${ALL_TARGET}; then \
		if [ -n "${BUILD_FAIL_MESSAGE}" ] ; then \
			${ECHO_MSG} "===> Compilation failed unexpectedly."; \
			(${ECHO_CMD} "${BUILD_FAIL_MESSAGE}") | ${FMT_80} ; \
		fi; \
		${FALSE}; \
	fi)
.endfor

do-install:
	${MKDIR} ${STAGEDIR}/var/games/xpuzzles
.for dir in ${XPUZZLES}
	@(cd ${INSTALL_WRKSRC}/${dir} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${FAKEROOT} \
	  ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor
	${RM} ${STAGEDIR}${PREFIX}/bin/play.sh
.for dir in ${XPUZZLES}
	${MV} ${STAGEDIR}/var/games/xpuzzles/${dir}.scores \
		${STAGEDIR}/var/games/xpuzzles/${dir}.scores.sample
.endfor

.include <bsd.port.mk>

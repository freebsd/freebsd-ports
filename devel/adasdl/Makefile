# New ports collection makefile for:   adasdl
# Date created:        21 December 2002
# Whom:                David Holm <david@realityrift.com>
#
# $FreeBSD$
#

PORTNAME=      adasdl
PORTVERSION=   20010504
PORTREVISION=	1
CATEGORIES=    devel
MASTER_SITES=  ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=    ${PORTNAME}
DISTNAME=      AdaSDL_${PORTVERSION}

MAINTAINER=	david@realityrift.com
COMMENT=	An Ada thin binding to SDL

LIB_DEPENDS=	${GL_DEPENDS}
BUILD_DEPENDS=	gnatmake:${PORTSDIR}/lang/gnat

USE_SDL=	mixer image sdl
USE_GMAKE=     yes
USE_REINPLACE= yes

do-patch:
	for i in `${FIND} ${WRKSRC} -name 'Makefile'`; do \
		${REINPLACE_CMD} -e '/gnatmake/!s/make\ /gmake\ /' $${i}; \
	done
	for i in `${FIND} ${WRKSRC} -name 'make.conf_x11'`; do \
		${REINPLACE_CMD} \
			-e 's,/usr/local,${LOCALBASE},g' \
			-e 's,/usr/X11R6,${X11BASE},g' \
			-e 's,-lSDL\ ,-lSDL-1.1\ ,' \
			-e 's,-lpthread,-pthread,' \
			-e 's,-lGL,-L${X11BASE}/lib\ -lX11 -lXext -lGL,' \
		$${i}; \
	done

do-build:
	cd ${WRKSRC}/AdaSDL && \
	${GMAKE} conf2x11 && \
	${GMAKE} bind
	cd ${WRKSRC}/AdaSDL_framebuff && \
	${GMAKE} conf2x11 && \
	${GMAKE} framebuff

.if !defined(WITHOUT_SDL_IMAGE)
	cd ${WRKSRC}/AdaSDL_image && \
	${GMAKE} conf2x11 && \
	${GMAKE} binding
.endif

.if !defined(WITHOUT_SDL_MIXER)
	cd ${WRKSRC}/AdaSDL_mixer && \
	${GMAKE} conf2x11 && \
	${GMAKE} binding
.endif

.if !defined(WITHOUT_OPENGL)
	cd ${WRKSRC}/AdaGL && \
	${GMAKE} conf2x11 && \
	${GMAKE} bind
.endif

do-install:
	${MKDIR} ${PREFIX}/lib/adaSDL
	for i in `cat pkg-plist|grep "lib/adaSDL/"|grep -v framebuffer|grep -v _mixer|grep -v _image|sed "s/lib\/adaSDL\///"`; do \
		${FIND} ${WRKSRC}/AdaSDL/binding -name $${i} -maxdepth 1 | \
			${INSTALL_DATA} `grep ""` ${PREFIX}/lib/adaSDL; \
	done
	for i in `cat pkg-plist|grep "lib/adaSDL/"|grep framebuffer|sed "s/lib\/adaSDL\///"`; do \
		${FIND} ${WRKSRC}/AdaSDL_framebuff -name $${i} -maxdepth 1 | \
			${INSTALL_DATA} `grep ""` ${PREFIX}/lib/adaSDL; \
	done
	${MKDIR} ${PREFIX}/share/adaSDL
	${MKDIR} ${PREFIX}/share/adaSDL/examples
	for i in `cat pkg-plist|grep "share/adaSDL/examples"|grep -v dirrm|sed "s/share\/adaSDL\/examples\///"`; do \
		${FIND} ${WRKSRC}/AdaSDL_framebuff/sdltests -name $${i} \
			-maxdepth 1 | ${INSTALL_DATA} \
			`grep ""` ${PREFIX}/share/adaSDL/examples; \
	done

.if !defined(WITHOUT_SDL_IMAGE)
	for i in `cat pkg-plist|grep "lib/adaSDL/"|grep _image|sed "s/lib\/adaSDL\///"`; do \
		${FIND} ${WRKSRC}/AdaSDL_image -name $${i} -maxdepth 1 | \
			${INSTALL_DATA} `grep ""` ${PREFIX}/lib/adaSDL; \
	done
.endif

.if !defined(WITHOUT_SDL_MIXER)
	for i in `cat pkg-plist|grep "lib/adaSDL/"|grep _mixer|sed "s/lib\/adaSDL\///"`; do \
		${FIND} ${WRKSRC}/AdaSDL_mixer -name $${i} -maxdepth 1 | \
			${INSTALL_DATA} `grep ""` ${PREFIX}/lib/adaSDL; \
	done
.endif

.if !defined(WITHOUT_OPENGL)
	${MKDIR} ${PREFIX}/lib/adaGL
	for i in `cat pkg-plist|grep "/adaGL/"|sed "s/lib\/adaGL\///"`; do \
		${FIND} ${WRKSRC}/AdaGL/GL -name $${i} -maxdepth 1 | \
			${INSTALL_DATA} `grep ""` ${PREFIX}/lib/adaGL; \
	done
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${GUNZIP_CMD} -dc ${DISTDIR}/${DISTNAME}.tar.gz \
	| ${TAR} -C ${WRKSRC} -xf -

post-install:
	@${ECHO}
	@${ECHO} "AdaSDL has been installed in ${PREFIX}/lib/adaSDL"
	@${ECHO} "AdaSDL examples have been installed in ${PREFIX}/share/adaSDL/examples"
.if !defined(WITHOUT_OPENGL)
	@${ECHO} "AdaGL has been installed in ${PREFIX}/lib/adaGL"
.endif
	@${ECHO}

.include <bsd.port.mk>

# New ports collection makefile for:	celestia
# Date created:				2002-05-17
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		celestia
PORTVERSION=		1.3.1
CATEGORIES=		astro
MASTER_SITES=		http://fresh.t-systems-sfr.com/unix/src/misc/
# ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	celestia

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Scriptable space flight simulator for X

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
OPTIONS=	KDE "KDE support" off
OPTIONS+=	LUA "Lua support" off
PLIST=		${WRKDIR}/pkg-plist
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_MESA=	yes
USE_X_PREFIX=	yes

# GTK+ support is deprecated and broken
CONFIGURE_ARGS=	--without-gtk

CONFIGURE_ENV=	\
	LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib -lm ${PTHREAD_LIBS}" \
	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}"

.if defined(WITH_KDE)
USE_KDELIBS_VER=	3
CONFIGURE_ARGS+=	--with-kde
.else
CONFIGURE_ARGS+=	--without-kde
.endif

.if defined(WITH_LUA)
LIB_DEPENDS+=		lua.5:${PORTSDIR}/lang/lua
CONFIGURE_ARGS+=	--with-lua
.else
CONFIGURE_ARGS+=	--without-lua
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

pre-patch:
	@${REINPLACE_CMD} -e \
's:-O2::g; s:-Wall::g; s:-ffast-math::g; s:-fexpensive-optimizations::g; s:! /bin/sh:! ${LOCALBASE}/bin/bash:g' \
	${WRKSRC}/configure

pre-install:
	@${ECHO_CMD} bin/celestia > ${PLIST}
	@${FIND} ${WRKSRC}/data/ -name '*.???' | \
		${SED} -e "s:^${WRKSRC}/:share/celestia/:g" >> ${PLIST}
	@${FIND} ${WRKSRC}/extras/ -name '*.ssc' | \
		${SED} -e "s:^${WRKSRC}/:share/celestia/:g" >> ${PLIST}
	@${FIND} ${WRKSRC}/fonts/ -name '*.txf' | \
		${SED} -e "s:^${WRKSRC}/:share/celestia/:g" >> ${PLIST}
.for ii in celestia.cfg demo.cel guide.cel start.cel
	@${ECHO_CMD} share/celestia/${ii} >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
.for ii in AUTHORS ChangeLog README TODO controls.txt
	@${ECHO_CMD} share/doc/celestia/${ii} >> ${PLIST}
.endfor
	@${FIND} ${WRKSRC}/manual/ -name '*.???*' | \
		${SED} -e "s:^${WRKSRC}/:share/doc/celestia/:g" >> ${PLIST}
.for ii in celestia/manual celestia
	@${ECHO_CMD} @dirrm share/doc/${ii} >> ${PLIST}
.endfor
.endif
	@${FIND} ${WRKSRC}/models/ -name '*.???' | \
		${SED} -e "s:^${WRKSRC}/:share/celestia/:g" >> ${PLIST}
	@${FIND} ${WRKSRC}/shaders/ -name '*.vp' | \
		${SED} -e "s:^${WRKSRC}/:share/celestia/:g" >> ${PLIST}
	@${FIND} ${WRKSRC}/textures/ -name '*.jpg' -o -name '*.png'| \
		${SED} -e "s:^${WRKSRC}/:share/celestia/:g" >> ${PLIST}
.for ii in /data /extras /textures/lores /textures/medres /textures /models \
	/shaders /fonts /
	@${ECHO_CMD} @dirrm share/celestia${ii} >> ${PLIST}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/celestia/celestia ${PREFIX}/bin/
.for ii in /data /extras /textures/lores /textures/medres /models /shaders \
	/fonts
	${MKDIR} ${DATADIR}${ii}
.endfor
	${INSTALL_DATA} ${WRKSRC}/data/*.??? ${DATADIR}/data/
	${INSTALL_DATA} ${WRKSRC}/extras/*.ssc ${DATADIR}/extras/
	${INSTALL_DATA} ${WRKSRC}/fonts/*.txf ${DATADIR}/fonts/
.for ii in celestia.cfg demo.cel guide.cel start.cel
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DATADIR}/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/manual
.for ii in AUTHORS ChangeLog README TODO controls.txt
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/manual/*.???* ${DOCSDIR}/manual/
.endif
	${INSTALL_DATA} ${WRKSRC}/models/*.??? ${DATADIR}/models/
	${INSTALL_DATA} ${WRKSRC}/shaders/*.vp ${DATADIR}/shaders/
	${INSTALL_DATA} ${WRKSRC}/textures/*.jpg \
		${WRKSRC}/textures/*.png ${DATADIR}/textures/
	${INSTALL_DATA} ${WRKSRC}/textures/lores/*.??? \
		${DATADIR}/textures/lores/
	${INSTALL_DATA} ${WRKSRC}/textures/medres/*.??? \
		${DATADIR}/textures/medres/

.include <bsd.port.post.mk>

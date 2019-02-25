# Created by: Seiichirou Hiraoka
# $FreeBSD$

PORTNAME=	xsystem35
DISTVERSION=	1.7.3-pre5
PORTREVISION=	4
CATEGORIES=	emulators games
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${DISTVERSION}.orig

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	AliceSoft System 3.5/3.6/3.8/3.9 on X Window System

LICENSE=	GPLv2+

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
		libltdl.so:devel/libltdl \
		libfreetype.so:print/freetype2

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_DEFINE_i386=	MMX
OPTIONS_DEFAULT_i386=	${MACHINE_CPU:tu:MMMX}

MMX_BUILD_DEPENDS=nasm:devel/nasm
MMX_CONFIGURE_ENABLE=mmx

EXTRACT_AFTER_ARGS=--exclude libltdl
USES=		gettext gmake gnome jpeg libtool localbase pkgconfig shebangfix
USE_GNOME=	gtk20
SHEBANG_FILES=	contrib/instgame
USE_XORG=	x11 xext xxf86vm
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X_LIBS="-lX11"
CONFIGURE_ARGS=	\
		--with-cachesize=20 \
		--with-glib-prefix=${NONEXISTENT} \
		--with-gtk-prefix=${NONEXISTENT} \
		--disable-static \
		--enable-audio=oss \
		--with-default-output=oss \
		--enable-midi=seq,extp,raw \
		--enable-cdrom=bsd,mp3
INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/:S/.orig//}
DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}

post-patch:
	@${CP} ${WRKSRC}/INSTALL ${WRKSRC}/doc/INSTALL
	@${REINPLACE_CMD} -e '/-lxpg4/d' \
		-e '/INCLTDL=/d; /LTDLINCL=/d' \
		-e '/LIBLTDL=/s/=.*/="-lltdl"/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} '/^SUBDIRS/s/ libltdl//' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's|__COUNTER__|__COUNTER_H__|' ${WRKSRC}/src/counter.h

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/instgame ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/contrib && ${COPYTREE_SHARE} \
		"*.*" ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_DATA} ${WRKSRC}/patch/pastel.diff \
		${WRKSRC}/src/xsys35rc.sample \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

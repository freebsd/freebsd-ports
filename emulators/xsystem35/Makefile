# Created by: Seiichirou Hiraoka
# $FreeBSD$

PORTNAME=	xsystem35
PORTVERSION=	1.7.2
PORTREVISION=	18
CATEGORIES=	emulators
MASTER_SITES=	http://8ne.sakura.ne.jp:20008/chika/unitbase/xsys35/down/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AliceSoft System 3.5/3.6/3.8/3.9 on X Window System

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

OPTIONS_DEFINE=	ESOUND DOCS EXAMPLES
OPTIONS_DEFINE_i386=	MMX
OPTIONS_DEFAULT_i386=	${MACHINE_CPU:tu:MMMX}

ESOUND_USE=	GNOME=esound
ESOUND_CONFIGURE_ON=--enable-audio=oss,esd --with-default-output=esd
MMX_BUILD_DEPENDS=nasm:${PORTSDIR}/devel/nasm
MMX_CONFIGURE_ENABLE=mmx

USES=		gettext gmake libtool shebangfix
SHEBANG_FILES=	contrib/instgame
USE_AUTOTOOLS=	autoconf:env
USE_GNOME=	gtk12
USE_XORG=	xxf86vm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-gettext \
		--with-cachesize=20 \
		--disable-static \
		--enable-audio=oss \
		--with-default-output=oss \
		--enable-midi=seq,extp,raw \
		--enable-cdrom=bsd,mp3
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}

post-patch:
	@${CP} ${WRKSRC}/INSTALL ${WRKSRC}/doc/INSTALL
	@${REINPLACE_CMD} '/-lxpg4/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} 's|__COUNTER__|__COUNTER_H__|' ${WRKSRC}/src/counter.h

pre-configure:
	(cd ${WRKSRC}/libltdl; ${AUTOCONF})

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/instgame ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc;\
		${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/xsys35rc.sample ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/contrib; \
		${INSTALL_DATA} *.* ${STAGEDIR}${EXAMPLESDIR})
	@(cd ${WRKSRC}/patch; \
		${INSTALL_DATA} pastel.diff ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

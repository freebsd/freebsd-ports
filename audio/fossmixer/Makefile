PORTNAME=	fossmixer
PORTVERSION=	0.0.3
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/detroit
DISTNAME=	detroit-0.2.3

MAINTAINER=	salojan@goto10.co
COMMENT=	Graphical mixer application for OSS
WWW=		https://detroit.sourceforge.net/app_fossmixer.html

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	noto-basic>0:x11-fonts/noto-basic
LIB_DEPENDS=	libao.so:audio/libao \
		libportaudio.so:audio/portaudio \
		libpulse-simple.so:audio/pulseaudio \
		libiconv.so:converters/libiconv \
		libltdl.so:devel/libltdl \
		libfreetype.so:print/freetype2

USES=		gettext-runtime gl perl5 pkgconfig tar:xz xorg
USE_GL=		gl
USE_PERL5=	patch build
USE_XORG=	x11 xext xrandr

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-bob \
		--disable-color \
		--disable-coords \
		--disable-draw \
		--disable-image \
		--disable-math \
		--disable-menu \
		--disable-remote \
		--sysconfdir="${ETCDIR}" \
		--with-libiconv="${LOCALBASE}" \
		--with-libintl="${LOCALBASE}" \
		--with-libltdl="${LOCALBASE}"

ALL_TARGET=
INSTALL_TARGET=	install-strip
CFLAGS_i386=	-msse2

post-patch:
	@(cd ${WRKSRC}/apps && ./build.sh fossmixer)

	@for i in alsa flac samplerate gnutls openssl librsvg-2.0; do \
		${REINPLACE_CMD} -e "s|$${i}|$${i}_EXCLUDE|g" ${WRKSRC}/configure ; \
	done

	@${REINPLACE_CMD} -e "s|^.*bobs.*$$||" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|@echo Compiling engine/$$< ; ||" ${WRKSRC}/engine/Makefile.in
	@${REINPLACE_CMD} -e "s|-O2|${CFLAGS}|" ${WRKSRC}/configure

post-install:
	@for i in conf res; do \
		if [ -e "${STAGEDIR}${PREFIX}/etc/fossmixer/fossmixer.$${i}" ]; then \
			${MV} -f \
				${STAGEDIR}${PREFIX}/etc/fossmixer/fossmixer.$${i} \
				${STAGEDIR}${PREFIX}/etc/fossmixer/fossmixer.$${i}.sample ; \
		fi ; \
	done

	@for i in NotoSans-Italic NotoSans-Regular; do \
		${LN} -sf \
			"${LOCALBASE}/share/fonts/noto/$${i}.ttf" \
			"${STAGEDIR}${PREFIX}/share/detroit/fonts/$${i}.ttf" ; \
	done

.include <bsd.port.mk>

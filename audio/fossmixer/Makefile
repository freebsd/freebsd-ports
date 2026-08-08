PORTNAME=	fossmixer
DISTVERSION=	0.0.6
CATEGORIES=	audio
MASTER_SITES=	SF/detroit
DISTNAME=	detroit-0.2.9
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} detroit-data-0.1.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	salojan@goto10.co
COMMENT=	Graphical mixer application for OSS
WWW=		https://detroit.sourceforge.net/app_fossmixer.html

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libfreetype.so:print/freetype2
RUN_DEPENDS=	noto-basic>0:x11-fonts/noto-basic

USES=		gettext-runtime gl gmake iconv:wchar_t pkgconfig tar:xz xorg
USE_GL=		gl
USE_XORG=	x11 xext xrandr

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-bob \
		--disable-collect \
		--disable-color \
		--disable-coords \
		--disable-draw \
		--disable-extended \
		--disable-image \
		--disable-input \
		--disable-log \
		--disable-math \
		--disable-message \
		--disable-output \
		--disable-remote \
		--disable-store \
		--sysconfdir="${ETCDIR}" \
		--with-libiconv="${ICONV_PREFIX}" \
		--with-libintl="${LOCALBASE}"

ALL_TARGET=
INSTALL_TARGET=	install-strip
CFLAGS_i386=	-msse2

post-patch:
	@(cd ${WRKSRC} && tar -zxf ${DISTDIR}/detroit-data-0.1.tar.gz)
	@(cd ${WRKSRC}/apps && ./build.sh fossmixer)

	@for i in alsa ao flac gnutls openssl portaudio-2.0 libpulse-simple sndio; do \
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

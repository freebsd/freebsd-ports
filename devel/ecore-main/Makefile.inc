CONFIGURE_ARGS=	--disable-ecore-con \
		--disable-ecore-directfb \
		--disable-ecore-evas \
		--disable-ecore-file \
		--disable-glib \
		--disable-gnutls \
		--disable-ecore-imf \
		--disable-ecore-imf_evas \
		--disable-ecore-input \
		--disable-ecore-input_evas \
		--disable-ecore-ipc \
		--disable-ecore-sdl \
		--disable-ecore-x

post-patch: ecore_drop_librt
ecore_drop_librt:
	@${REINPLACE_CMD} -E -e 's,(rt_libs=).*,\1,g' ${WRKSRC}/configure

PATCHDIR=	"../../devel/ecore-main/files"

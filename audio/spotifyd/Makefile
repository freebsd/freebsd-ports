# $FreeBSD$

PORTNAME=	spotifyd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.3-12
DISTVERSIONSUFFIX=	-g47cc0bc
CATEGORIES=	audio

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Spotify daemon

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENCE

LIB_DEPENDS=	libogg.so:audio/libogg

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Spotifyd
GH_TUPLE=	plietar:rust-alsa:8c63543fa0ccd971cf15f5675293d19febd6f79e:alsa \
		plietar:dns-parser:1d3e5a5591bc72eb061c23bd426c4a25f2f73791:dnsparser \
		librespot-org:librespot:3614404f18bcf74b1cc2a82d8c4c675f1de34e63:librespot \
		plietar:rust-mdns:0974ab4ff7874437e11a89037c8258362a0061f8:mdns \
		awmath:rust-crypto:394c247254dbe2ac5d44483232cf335d10cf0260:rustcrypto \
		plietar:rust-tremor:5958cc302e78f535dad90e9665da981ddff4000a:tremor

CARGO_CRATES=	adler32-1.0.3 \
		aho-corasick-0.6.8 \
		alsa-0.2.1 \
		alsa-sys-0.1.2 \
		arrayvec-0.4.7 \
		atty-0.2.11 \
		backtrace-0.3.9 \
		backtrace-sys-0.1.24 \
		base64-0.5.2 \
		base64-0.6.0 \
		base64-0.9.3 \
		bit-set-0.4.0 \
		bit-vec-0.4.4 \
		bitflags-0.3.3 \
		bitflags-0.7.0 \
		bitflags-0.9.1 \
		bitflags-1.0.4 \
		build_const-0.2.1 \
		byteorder-0.5.3 \
		byteorder-1.2.6 \
		bytes-0.4.10 \
		c_linked_list-1.1.1 \
		cc-1.0.25 \
		cfg-if-0.1.6 \
		chrono-0.4.6 \
		cloudabi-0.0.3 \
		core-foundation-0.5.1 \
		core-foundation-sys-0.5.1 \
		crc-1.8.1 \
		crossbeam-deque-0.6.1 \
		crossbeam-epoch-0.5.2 \
		crossbeam-utils-0.5.0 \
		ctrlc-3.1.1 \
		daemonize-0.2.3 \
		dbus-0.6.3 \
		dbus-tokio-0.2.1 \
		derive-error-chain-0.10.1 \
		derive_builder-0.5.1 \
		derive_builder_core-0.2.0 \
		dotenv-0.10.1 \
		dtoa-0.4.3 \
		either-1.5.0 \
		encoding_rs-0.8.10 \
		env_logger-0.4.3 \
		env_logger-0.5.13 \
		error-chain-0.10.0 \
		error-chain-0.11.0 \
		extprim-1.6.0 \
		failure-0.1.3 \
		failure_derive-0.1.3 \
		fnv-1.0.6 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.25 \
		futures-cpupool-0.1.8 \
		gcc-0.3.55 \
		get_if_addrs-0.5.3 \
		get_if_addrs-sys-0.1.1 \
		getopts-0.2.18 \
		h2-0.1.13 \
		hostname-0.1.5 \
		http-0.1.13 \
		httparse-1.3.3 \
		humantime-1.1.1 \
		hyper-0.11.27 \
		hyper-0.12.12 \
		hyper-proxy-0.4.1 \
		hyper-tls-0.3.1 \
		idna-0.1.5 \
		indexmap-1.0.1 \
		iovec-0.1.2 \
		itertools-0.7.8 \
		itoa-0.3.4 \
		itoa-0.4.3 \
		kernel32-sys-0.2.2 \
		language-tags-0.2.2 \
		lazy_static-0.2.11 \
		lazy_static-1.1.0 \
		lazycell-1.2.0 \
		lewton-0.8.0 \
		libc-0.2.43 \
		libdbus-sys-0.1.4 \
		libflate-0.1.18 \
		libpulse-sys-0.0.0 \
		linear-map-1.2.0 \
		lock_api-0.1.4 \
		log-0.3.9 \
		log-0.4.5 \
		matches-0.1.8 \
		memchr-2.1.0 \
		memoffset-0.2.1 \
		mime-0.3.12 \
		mime_guess-2.0.0-alpha.6 \
		mio-0.6.16 \
		mio-uds-0.6.7 \
		miow-0.2.1 \
		multimap-0.4.0 \
		native-tls-0.2.1 \
		net2-0.2.33 \
		nix-0.11.0 \
		nix-0.9.0 \
		nodrop-0.1.12 \
		num-bigint-0.1.44 \
		num-integer-0.1.39 \
		num-traits-0.1.43 \
		num-traits-0.2.6 \
		num_cpus-1.8.0 \
		ogg-0.5.1 \
		ogg-sys-0.0.9 \
		openssl-0.10.14 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.39 \
		owning_ref-0.3.3 \
		parking_lot-0.6.4 \
		parking_lot_core-0.3.1 \
		percent-encoding-1.0.1 \
		phf-0.7.23 \
		phf_codegen-0.7.23 \
		phf_generator-0.7.23 \
		phf_shared-0.7.23 \
		pkg-config-0.3.14 \
		portaudio-rs-0.3.0 \
		portaudio-sys-0.1.1 \
		proc-macro2-0.4.20 \
		protobuf-1.7.4 \
		quick-error-1.2.2 \
		quote-0.3.15 \
		quote-0.6.8 \
		rand-0.3.22 \
		rand-0.4.3 \
		rand-0.5.5 \
		rand_core-0.2.2 \
		rand_core-0.3.0 \
		random-0.12.2 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		regex-0.2.11 \
		regex-1.0.5 \
		regex-syntax-0.5.6 \
		regex-syntax-0.6.2 \
		relay-0.1.1 \
		remove_dir_all-0.5.1 \
		reqwest-0.9.3 \
		rpassword-0.3.1 \
		rspotify-0.2.5 \
		rust-crypto-0.2.36 \
		rust-ini-0.10.3 \
		rustc-demangle-0.1.9 \
		rustc-serialize-0.3.24 \
		rustc_version-0.2.3 \
		ryu-0.2.6 \
		safemem-0.2.0 \
		safemem-0.3.0 \
		schannel-0.1.14 \
		scoped-tls-0.1.2 \
		scopeguard-0.3.3 \
		security-framework-0.2.1 \
		security-framework-sys-0.2.1 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-0.9.15 \
		serde-1.0.80 \
		serde_codegen_internals-0.14.2 \
		serde_derive-0.9.15 \
		serde_derive-1.0.80 \
		serde_json-0.9.10 \
		serde_json-1.0.32 \
		serde_urlencoded-0.5.3 \
		shannon-0.2.0 \
		simplelog-0.4.4 \
		siphasher-0.2.3 \
		slab-0.3.0 \
		slab-0.4.1 \
		smallvec-0.2.1 \
		smallvec-0.6.5 \
		socket2-0.2.4 \
		stable_deref_trait-1.1.1 \
		string-0.1.1 \
		syn-0.11.11 \
		syn-0.15.13 \
		synom-0.11.3 \
		synstructure-0.10.0 \
		syslog-3.3.0 \
		take-0.1.0 \
		tempfile-2.2.0 \
		tempfile-3.0.4 \
		term-0.4.6 \
		termcolor-1.0.4 \
		termion-1.5.1 \
		termios-0.2.2 \
		thread_local-0.3.6 \
		time-0.1.40 \
		tokio-0.1.11 \
		tokio-codec-0.1.1 \
		tokio-core-0.1.17 \
		tokio-current-thread-0.1.3 \
		tokio-executor-0.1.5 \
		tokio-fs-0.1.3 \
		tokio-io-0.1.9 \
		tokio-proto-0.1.1 \
		tokio-reactor-0.1.6 \
		tokio-service-0.1.0 \
		tokio-signal-0.1.5 \
		tokio-tcp-0.1.2 \
		tokio-threadpool-0.1.7 \
		tokio-timer-0.2.7 \
		tokio-udp-0.1.2 \
		tokio-uds-0.2.2 \
		try-lock-0.1.0 \
		try-lock-0.2.2 \
		ucd-util-0.1.1 \
		unicase-1.4.2 \
		unicase-2.2.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.7 \
		unicode-width-0.1.5 \
		unicode-xid-0.0.4 \
		unicode-xid-0.1.0 \
		unix_socket-0.5.0 \
		unreachable-1.0.0 \
		url-1.7.1 \
		utf8-ranges-1.0.1 \
		uuid-0.4.0 \
		uuid-0.7.1 \
		vcpkg-0.2.6 \
		vergen-0.1.1 \
		version_check-0.1.5 \
		void-1.0.2 \
		want-0.0.4 \
		want-0.0.6 \
		webbrowser-0.2.2 \
		winapi-0.2.8 \
		winapi-0.3.6 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.1 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1 \
		winutil-0.1.1 \
		ws2_32-sys-0.2.1 \
		xdg-2.1.0
CARGO_USE_GITHUB=	yes
CARGO_GH_CARGOTOML=	${CARGO_CARGOTOML} \
			${WRKSRC_alsa}/Cargo.toml \
			${WRKSRC_dnsparser}/Cargo.toml \
			${WRKSRC_librespot}/audio/Cargo.toml \
			${WRKSRC_librespot}/Cargo.toml \
			${WRKSRC_librespot}/connect/Cargo.toml \
			${WRKSRC_librespot}/playback/Cargo.toml \
			${WRKSRC_mdns}/Cargo.toml \
			${WRKSRC_rustcrypto}/Cargo.toml \
			${WRKSRC_tremor}/Cargo.toml

CARGO_BUILD_ARGS=	--no-default-features
CARGO_INSTALL_ARGS=	--no-default-features
CARGO_TEST_ARGS=	--no-default-features

PLIST_FILES=	bin/spotifyd
PORTDOCS=	README.md

OPTIONS_DEFINE=		DBUS DOCS PORTAUDIO PULSEAUDIO
OPTIONS_DEFAULT=	PORTAUDIO

DBUS_DESC=		D-Bus MPRIS support

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_VARS=		CARGO_FEATURES+=dbus_mpris

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_VARS=		CARGO_FEATURES+=portaudio_backend

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_VARS=	CARGO_FEATURES+=pulseaudio_backend

post-patch:
	@${REINPLACE_CMD} 's,/etc/,${PREFIX}/etc/,g' ${WRKSRC}/src/config.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spotifyd

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

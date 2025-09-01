PORTNAME=	sctd
DISTVERSION=	0.2.0
PORTREVISION=	43
CATEGORIES=	accessibility

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Set color temperature (sct) daemon
WWW=		https://github.com/amir/sctd

LICENSE=	CC0-1.0 MIT
LICENSE_COMB=	multi
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSE

USES=			cargo xorg
USE_GITHUB=		yes
GH_ACCOUNT=		amir
USE_XORG=		x11 xrandr
CARGO_CRATES=	ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		bitflags-1.2.1 \
		cfg-if-0.1.10 \
		chrono-0.4.11 \
		clap-2.33.0 \
		env_logger-0.7.1 \
		hermit-abi-0.1.8 \
		humantime-1.3.0 \
		libc-0.2.68 \
		log-0.4.8 \
		num-integer-0.1.42 \
		num-traits-0.2.11 \
		pkg-config-0.3.17 \
		quick-error-1.2.3 \
		redox_syscall-0.1.56 \
		strsim-0.8.0 \
		textwrap-0.11.0 \
		time-0.1.42 \
		unicode-width-0.1.7 \
		vec_map-0.8.1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		x11-2.18.2 \
		spa@git+https://github.com/amir/spa-rs?branch=pub-SolarPos\#fa80d0ce99d675674cf1a7cc9cf2ee2e33f501ea

PLIST_FILES=	bin/sctd

.include <bsd.port.mk>

PORTNAME=	elevenlabs-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	audio

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Command-line interface for the ElevenLabs platform
WWW=		https://github.com/elevenlabs/cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# The keyring crate's "vendored" feature makes libdbus-sys build a bundled
# copy of D-Bus; files/patch-Cargo.toml drops it so the system library is
# used instead.  OPENSSL_NO_VENDOR does the same for openssl-sys.
LIB_DEPENDS=	libdbus-1.so:devel/dbus

USES=		cargo pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	elevenlabs
GH_PROJECT=	cli

CARGO_ENV=	OPENSSL_NO_VENDOR=1

PLIST_FILES=	bin/elevenlabs \
		share/man/man1/elevenlabs.1.gz

OPTIONS_DEFINE=	COMPLETIONS

# The CLI exposes the whole ElevenLabs API as subcommands, so the generated
# completion scripts are about 7MB in total.
COMPLETIONS_DESC=	Install shell completion scripts (large)

COMPLETIONS_PLIST_FILES=	share/bash-completion/completions/elevenlabs \
		share/fish/vendor_completions.d/elevenlabs.fish \
		share/zsh/site-functions/_elevenlabs

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${STAGEDIR}${PREFIX}/bin/elevenlabs man > \
		${STAGEDIR}${PREFIX}/share/man/man1/elevenlabs.1

post-install-COMPLETIONS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${STAGEDIR}${PREFIX}/bin/elevenlabs completion bash > \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/elevenlabs
	${STAGEDIR}${PREFIX}/bin/elevenlabs completion fish > \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/elevenlabs.fish
	${STAGEDIR}${PREFIX}/bin/elevenlabs completion zsh > \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_elevenlabs

.include <bsd.port.mk>

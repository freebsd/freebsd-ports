PORTNAME=	amber
DISTVERSION=	0.3.1-alpha
CATEGORIES=	lang
PKGNAMESUFFIX=	-language

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Amber: the programming language compiled to bash
WWW=		https://amber-lang.com

LICENSE=	GPLv3

RUN_DEPENDS=	bash:shells/bash

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	Ph0enixKM
GH_PROJECT=	Amber

CARGO_CRATES=	bitflags-2.4.0 \
		capitalize-0.1.0 \
		cc-1.0.83 \
		colored-2.0.4 \
		either-1.9.0 \
		errno-0.3.3 \
		errno-dragonfly-0.1.2 \
		heraclitus-compiler-1.5.8 \
		hermit-abi-0.3.2 \
		is-terminal-0.4.9 \
		itertools-0.10.5 \
		lazy_static-1.4.0 \
		libc-0.2.147 \
		linux-raw-sys-0.4.5 \
		pad-0.1.6 \
		rustix-0.38.10 \
		similar-string-1.4.3 \
		unicode-width-0.1.10 \
		windows-sys-0.48.0 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|"/bin/bash"|"${LOCALBASE}/bin/bash"|' ${WRKSRC}/src/compiler.rs

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

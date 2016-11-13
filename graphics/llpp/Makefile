# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	llpp
PORTVERSION=	22
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://repo.or.cz/llpp.git/snapshot/
DISTNAME=	561dc5673cea431e930668b0d87b0c4b31a36b39

MAINTAINER=	t@tobik.me
COMMENT=	PDF pager

# llpp itself is in the public domain, but it bundles lablGL which
# uses a BSD 3-clause license and statically links to mupdf which is
# AGPLv3 licensed.
LICENSE=	PUBLIC_DOMAIN BSD3CLAUSE AGPLv3
LICENSE_COMB=	multi
LICENSE_NAME_PUBLIC_DOMAIN=	Public Domain
LICENSE_FILE_PUBLIC_DOMAIN=	${WRKSRC}/README
LICENSE_PERMS_PUBLIC_DOMAIN=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	gsed:textproc/gsed \
		${LOCALBASE}/lib/libmupdf.a:graphics/mupdf
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjbig2dec.so:graphics/jbig2dec \
		libopenjp2.so:graphics/openjpeg
RUN_DEPENDS=	xsel:x11/xsel-conrad

STRIP=	# Stripping renders the executable unusable, so don't do it for now
USES=		desktop-file-utils gmake jpeg
USE_GL=		gl
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_OPENGL=	yes
USE_XORG=	x11 xext

WRKSRC=		${WRKDIR}/${PORTNAME}-561dc56

do-build:
	(cd ${WRKSRC} && ${SETENV} \
		LOCALBASE="${LOCALBASE}" \
		PORTVERSION="${PORTVERSION}" \
		${SH} build.sh build/)
	(cd ${WRKSRC}/misc/completions && ${GMAKE})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/llpp ${STAGEDIR}${PREFIX}/bin/llpp
	${INSTALL_SCRIPT} ${WRKSRC}/misc/llppac ${STAGEDIR}${PREFIX}/bin/llppac
	${INSTALL_DATA} ${WRKSRC}/misc/llpp.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/misc/completions/bash/llpp ${STAGEDIR}${PREFIX}/etc/bash_completion.d/_llpp.bash
	${INSTALL_DATA} ${WRKSRC}/misc/completions/bash/llppac ${STAGEDIR}${PREFIX}/etc/bash_completion.d/_llppac.bash
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/completions/zsh/llpp ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_llpp
	${INSTALL_DATA} ${WRKSRC}/misc/completions/zsh/llppac ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_llppac

.include <bsd.port.mk>

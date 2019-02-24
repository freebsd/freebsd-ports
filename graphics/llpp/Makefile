# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	llpp
PORTVERSION=	25
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://repo.or.cz/llpp.git/snapshot/
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	PDF pager

# llpp itself is in the public domain, but it bundles lablGL which
# uses a BSD 3-clause license
LICENSE=	PUBLIC_DOMAIN BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_NAME_PUBLIC_DOMAIN=	Public Domain
LICENSE_FILE_PUBLIC_DOMAIN=	${WRKSRC}/README
LICENSE_PERMS_PUBLIC_DOMAIN=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN=		fails to build
DEPRECATED=	fails to build with mupdf 1.14.0 and unable to update due to outdated lang/ocaml
EXPIRATION_DATE=	2019-03-31

BUILD_DEPENDS=	gsed:textproc/gsed
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjbig2dec.so:graphics/jbig2dec \
		libmupdf.so:graphics/mupdf \
		libopenjp2.so:graphics/openjpeg
RUN_DEPENDS=	xsel:x11/xsel-conrad

STRIP=	# Stripping renders the executable unusable, so don't do it for now
USES=		desktop-file-utils gmake jpeg ssl
USE_GL=		gl
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_OPENGL=	yes
USE_XORG=	x11 xext

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTNAME}-14986ea

do-build:
	@(cd ${WRKSRC} && ${SETENV} \
		LOCALBASE="${LOCALBASE}" \
		PORTVERSION="${PORTVERSION}" \
		${SH} build.sh build)
	@(cd ${WRKSRC}/misc/completions && ${GMAKE})

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

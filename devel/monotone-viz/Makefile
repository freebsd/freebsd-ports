# Created by: Tarasov Alexey <master@preved.cn>
# $FreeBSD$

PORTNAME=	monotone-viz
PORTVERSION=	1.0.2
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://oandrieu.nerim.net/monotone-viz/

PATCH_SITES=	DEBIAN_POOL
PATCHFILES=	${PORTNAME}_${PORTVERSION}-4.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visual interface for Monotone VCS with revision graphs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xpmtoppm:graphics/netpbm \
		lablgtk2:x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS=	dot:graphics/graphviz \
		mtn:devel/monotone \
		bash:shells/bash \
		lablgtk2:x11-toolkits/ocaml-lablgtk2

USES=		gmake pkgconfig
USE_OCAML=	yes
USE_OCAML_CAMLP4=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-local-lablgtk

ALL_TARGET=	monotone-viz
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/monotone-viz share/pixmaps/monotone-viz.png

DESKTOP_ENTRIES="Monotone-viz" "" "monotone-viz" "monotone-viz" \
		"Development;RevisionControl;GTK;" ""

post-patch:
.for i in 10-new-stdio.diff 20-dot-rankdir.diff 50-ocaml-4.02.2.diff
	@${PATCH} -d ${WRKSRC} -p1 --quiet < ${WRKSRC}/debian/patches/${i}
.endfor
	@${REINPLACE_CMD} -e 's|"/bin/bash"|"${LOCALBASE}/bin/bash"|' \
		${WRKSRC}/agraph.ml

# Monkey patch the icon.ml into an xpm file.
post-build:
	@${SED} -e 's|^(\(\* XPM \*\))$$|/\1/|; \
		 s/^let \(monotone_xpm\) = \[|$$/static char * \1[] = {/; \
		 s/";$$/",/; s/|\]$$/};/; /GdkPixbuf/d' ${WRKSRC}/icon.ml | \
		xpmtoppm --alphaout=${WRKDIR}/icon.pgm | \
		pnmtopng --alpha=${WRKDIR}/icon.pgm > ${WRKDIR}/monotone-viz.png

post-install:
	${INSTALL_DATA} ${WRKDIR}/monotone-viz.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/monotone-viz

.include <bsd.port.mk>

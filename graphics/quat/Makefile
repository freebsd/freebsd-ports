# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	quat
PORTVERSION=	1.20
CATEGORIES=	graphics
MASTER_SITES=	https://www.physcip.uni-stuttgart.de/pages/~phy11733/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Three-dimensional fractal creator (command line only)

LICENSE=	GPLv2+

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gui \
		--datadir=${PREFIX}/share/doc

PORTDOCS=	*
PLIST_FILES=	bin/quat-txt

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -ffast-math

post-patch:
	@${REINPLACE_CMD} -E -e \
		's,-(march=pentium|O3|ffast-math),,g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e \
		's|-I\.[[:space:]]+-I\$$\(srcdir\)[[:space:]]+||' \
		${WRKSRC}/kernel/Makefile.in
# disable data file installation since distfile does not do
# The Right Thing(TM)
	@${REINPLACE_CMD} -E -e \
		's|^(install-data-am:).*$$|\1| ; \
		 s|^(SUBDIRS.*)doc|\1|' \
		${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.mk>

PORTNAME=	quat
PORTVERSION=	1.20
CATEGORIES=	graphics
MASTER_SITES=	https://www.physcip.uni-stuttgart.de/pages/~phy11733/download/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Three-dimensional fractal creator (command line only)
WWW=		https://www.physcip.uni-stuttgart.de/pages/~phy11733/index_e.html

LICENSE=	GPLv2+

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gui \
		--datadir=${PREFIX}/share/doc

PLIST_FILES=	bin/quat-txt
PORTDOCS=	*

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -ffast-math

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

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

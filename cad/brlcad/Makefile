PORTNAME=	brlcad
PORTVERSION=	7.32.6
CATEGORIES=	cad
MASTER_SITES=	https://github.com/BRL-CAD/brlcad/releases/download/rel-${PORTVERSION:S/./-/g}/

MAINTAINER=	ports@freebsd.org
COMMENT=	CSG modelling system from the US Ballistic Research Laboratory
WWW=		https://brlcad.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xsltproc:textproc/libxslt
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libdrm.so:graphics/libdrm \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		bison:alias cmake:insource cpe gl pkgconfig python:env \
		tar:bzip2 tk xorg
USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xau xcb xdamage xdmcp xext xfixes xft xi \
		xorgproto xrender xscrnsaver xt xxf86vm

CMAKE_OFF=	BRLCAD_ENABLE_STRICT
CMAKE_INSTALL_PREFIX=	${PREFIX}/${PORTNAME}
CXXFLAGS_powerpc64=	-mvsx

TEST_TARGET=	check

CONFLICTS_INSTALL=	py[23][0-9]-epsilon

MANDIRS=	${PREFIX}/${PORTNAME}/share/man
NO_MTREE=	yes

WRKSRC=${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
USES+=	llvm:max=14
.endif

post-patch:
	@${REINPLACE_CMD} -e 's+-exact Tcl 8\.6\.10+Tcl 8.6+' \
		${WRKSRC}/src/other/tcl/library/init.tcl

pre-install:
	${CP} ${FILESDIR}/mged.sh ${WRKSRC}
	${REINPLACE_CMD} -e 's+%%BRLCAD_ROOT%%+${PREFIX}/${PORTNAME}+g;' ${WRKSRC}/mged.sh

# note that installing outside of PREFIX wigs out package stuff... :/
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mged.sh ${STAGEDIR}${PREFIX}/bin/mged.sh

regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} test)

.include <bsd.port.mk>

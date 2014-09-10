# $FreeBSD$

PORTNAME=	tiffgt
PORTVERSION=	4.0.3
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/libtiff/ \
		http://download.osgeo.org/libtiff/
DISTNAME=	tiff-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	X11 Tools for working with TIFF images

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libjbig.so:${PORTSDIR}/graphics/jbigkit \
		libtiff.so:${PORTSDIR}/${PKGCATEGORY}/tiff

#TODO: Remove :oldver together with VERSION_INFO patching in pre-configure.
USES=		libtool:oldver
USE_XORG=	sm ice xmu xi x11
USE_GL=		glut glu gl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-jpeg-include-dir=${LOCALBASE}/include \
			--with-jpeg-lib-dir=${LOCALBASE}/lib \
			--with-x --with-libgl
PLIST_FILES=	bin/tiffgt man/man1/tiffgt.1.gz

pre-configure:
	${REINPLACE_CMD} \
		-e 's|^LIBTIFF_VERSION_INFO =.*$$|LIBTIFF_VERSION_INFO = 4:0:0|' \
		${WRKSRC}/libtiff/Makefile.in
	${REINPLACE_CMD} -e 's|^docfiles|no-docfiles|' \
		-e 's|man html|man|' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/.libs/tiffgt ${STAGEDIR}/${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/tiffgt.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>

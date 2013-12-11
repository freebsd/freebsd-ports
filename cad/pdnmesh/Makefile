# Created by: Sarod Yatawatta <sarod@cs.pdn.ac.lk>
# $FreeBSD$

PORTNAME=	pdnmesh
PORTVERSION=	0.2.2
PORTREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mesh generator and solver for Finite Element problems

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libdrm.so:${PORTSDIR}/graphics/libdrm \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libgtkglext.so:${PORTSDIR}/x11-toolkits/gtkglext

OPTIONS_DEFINE=	ATLAS DOCS EXAMPLES
ATLAS_DESC=	Enable ATLAS support

USES=		pkgconfig gettext iconv
USE_FORTRAN=	yes
USE_GL=		glu
USE_GNOME=	gdkpixbuf2 gtk20
USE_XORG=	ice pixman sm x11 xau xcb xcomposite xcursor xdamage xdmcp \
		xext xfixes xmu xi xinerama xrandr xrender xt xxf86vm
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lm

MAN1=		pdnmesh.1
MAN5=		pdnmesh_input.5

DESKTOP_ENTRIES="pdnMesh" "${COMMENT}" "" "${PORTNAME}" "" "true"

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
CONFIGURE_ARGS+=--with-blas=cblas --with-lapack=alapack
.else
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas
LIB_DEPENDS+=	liblapack.so:${PORTSDIR}/math/lapack
CONFIGURE_ARGS+=--with-blas=blas --with-lapack=lapack
.endif

post-patch:
	@${REINPLACE_CMD}-e \
		'/^SUBDIRS/s|doc|| ; \
		 s|^pkgdata_DATA|#pkgdata_DATA|' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} \
		&& ${INSTALL_DATA} ChangeLog ${DOCSDIR} \
		&& ${INSTALL_DATA} README ${DOCSDIR})
	@${MKDIR} ${DOCSDIR}/tutorial
	(cd ${WRKSRC}/doc/tutorial \
		&& ${INSTALL_DATA} README ${DOCSDIR}/tutorial \
		&& ${INSTALL_DATA} tutorial.* ${DOCSDIR}/tutorial)
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(${TAR} -C ${WRKSRC}/doc/examples --exclude "*Makefile*" -cf - . | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -)
	@${FIND} ${EXAMPLESDIR} | ${XARGS} ${CHOWN} ${SHREOWN}:${SHAREGRP}
	@${FIND} ${EXAMPLESDIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${EXAMPLESDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif

.include <bsd.port.mk>

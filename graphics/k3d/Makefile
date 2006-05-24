# ex:ts=8
# Ports collection makefile for:	k3d
# Date created:			Jun 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	k3d
PORTVERSION=	0.4.4.0
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A free 3D modeling, animation, and rendering system

BUILD_DEPENDS=	${X11BASE}/lib/libplibul.a:${PORTSDIR}/x11-toolkits/plib
#		${X11BASE}/lib/libode.a:${PORTSDIR}/devel/ode
LIB_DEPENDS=	sigc.1:${PORTSDIR}/devel/libsigc++ \
		freetype.9:${PORTSDIR}/print/freetype2 \
		tiff.4:${PORTSDIR}/graphics/tiff \
		Magick++.10:${PORTSDIR}/graphics/ImageMagick \
		netpbm.1:${PORTSDIR}/graphics/netpbm \
		Half.2:${PORTSDIR}/graphics/OpenEXR \
		gts.5:${PORTSDIR}/graphics/gts

CONFLICTS=	atlas-3* superlu-3*

USE_GL=		yes
USE_GNOME=	gnometarget gtk12 libxslt
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	\
	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include" \
	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--without-docbook --without-graphviz \
		--with-openexr --with-plib --with-gts
#		--with-ode
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=	k3d.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

.if ${ARCH} == "amd64"
BROKEN=		"Does not compile on amd64"
.endif

post-install:
.for dir in ${PREFIX}/include/k3d ${PREFIX}/share/k3d ${PREFIX}/lib/k3d
	@${FIND} ${dir} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>

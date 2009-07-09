# New ports collection makefile for:	smasher
# Date created:		22 June 2009
# Whom:			chris@officialunix.com
#
# $FreeBSD$
#

PORTNAME=	smasher
PORTVERSION=	1.0.5
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	chris@officialunix.com
COMMENT=	Cross platform audio loop slicer

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		mad.2:${PORTSDIR}/audio/libmad

ONLY_FOR_ARCHS=		i386
ONLY_FOR_ARCHS_REASON=		At the momment does not build on AMD64 ia64

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${LOCALBASE}/bin/wxgtk2-2.8-config \
		--datarootdir="${PREFIX}/share" --libdir="${LOCALBASE}/lib" \
		--localedir="${PREFIX}/share/locale" --includedir="${LOCALBASE}/include"

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"

USE_XORG=	x11
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_WX=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/pixmaps|${LOCALBASE}/share/pixmaps|g' \
		${WRKSRC}/src/Makefile.am ${WRKSRC}/src/Makefile.in

	@${REINPLACE_CMD} -e 's|/usr/share/applications|${LOCALBASE}/share/applications|g' \
		${WRKSRC}/src/Makefile.am ${WRKSRC}/src/Makefile.in

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 604000
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>

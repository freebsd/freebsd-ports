# Created by: chris@officialunix.com
# $FreeBSD$

PORTNAME=	smasher
PORTVERSION=	1.1.6
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross platform audio loop slicer

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		mad.2:${PORTSDIR}/audio/libmad \
		csound64.5:${PORTSDIR}/audio/csound

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PKGCONFIG=	build
USE_WX=		yes
WX_CONF_ARGS=	absolute

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/pixmaps|${PREFIX}/share/pixmaps|g' \
		-e 's|/usr/share/applications|${DESKTOPDIR}|g' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>

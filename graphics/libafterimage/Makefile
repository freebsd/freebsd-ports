# ex:ts=8
# New ports collection makefile for:	libAfterImage
# Date created:			Oct 7, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libafterimage
PORTVERSION=	0.81
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	afterstep
DISTNAME=	libAfterImage-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		ungif:${PORTSDIR}/graphics/libungif \
		tiff:${PORTSDIR}/graphics/tiff \
		freetype:${PORTSDIR}/print/freetype2 \
		AfterBase:${PORTSDIR}/devel/libafterbase

USE_X_PREFIX=	yes
FREETYPE_CONFIG?=	${LOCALBASE}/bin/freetype-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV= \
	CPPFLAGS="${CXXFLAGS} `${FREETYPE_CONFIG} --cflags` -I${LOCALBASE}/include -I${X11BASE}/include" \
	LIBS="`${FREETYPE_CONFIG} --libs`"
CONFIGURE_ARGS=	--enable-sharedlibs --with-x
WRKSRC=		${WRKDIR}/libAfterImage
INSTALLS_SHLIB=	yes

MANCOMPRESSED=	no
MAN3=	afterimage.3x asfont.3x asimage.3x asvisual.3x blender.3x import.3x

post-patch:
	@${PERL} -pi -e "s,\@CFLAGS\@,\@CPPFLAGS\@,g" ${WRKSRC}/Makefile.in

pre-install:
	@${TOUCH} ${WRKSRC}/doc/export.man

post-install:
	@${MV} -f ${PREFIX}/lib/libAfterImage.so.0.81 ${PREFIX}/lib/libAfterImage.so.0
	@${RM} -f ${MAN3PREFIX}/man/man3/export.3x

.include <bsd.port.mk>

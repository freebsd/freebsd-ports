# ex:ts=8
# New ports collection makefile for:	libAfterImage
# Date created:			Oct 7, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libafterimage
PORTVERSION=	0.91
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	afterstep
DISTNAME=	libAfterImage-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2	# XXX
LIB_DEPENDS=	AfterBase.0:${PORTSDIR}/devel/libafterbase \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.8:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/libAfterImage

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--enable-sharedlibs --with-builtin-xpm --with-x
INSTALLS_SHLIB=	yes

MAN1=	ascompose.1x
MAN3=	afterimage.3x ascmap.3x asfont.3x asimage.3x asvisual.3x blender.3x \
	export.3x import.3x transform.3x ximage.3x

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS+=	--enable--mmx-optimization
.endif

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install.doc
.endif

post-patch:
	@${PERL} -pi -e 's|-lgif|-lungif|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name '*.[ch]' | xargs ${PERL} -pi -e \
		's|<malloc.h>|<stdlib.h>|g'

.include <bsd.port.post.mk>

# New ports collection makefile for:	inkscape
# Date created:		17 Nov 2003
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	inkscape
PORTVERSION=	0.38.1
PORTREVISION=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program seeks to become a full featured open source SVG editor

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		sigc-1.2.5:${PORTSDIR}/devel/libsigc++12
RUN_DEPENDS=	${SITE_PERL}/XML/XQL.pm:${PORTSDIR}/textproc/p5-XML-XQL

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack lthack intlhack libglade2 libartlgpl2 \
		desktopfileutils libgnomeprintui
USE_REINPLACE=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ARGS=	--with-popt \
		--with-gnome-print
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 -I${X11BASE}/include -I${LOCALBASE}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib -L${LOCALBASE}"

MAN1=		inkscape.1 inkview.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=  ${PATCHDIR}/extra-patch-old_gcc_bugs
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' \
		${WRKSRC}/src/helper/action.cpp \
		${WRKSRC}/src/libarikkei/arikkei-token.cpp
	@${REINPLACE_CMD} -e 's|round|rint|g' \
		${WRKSRC}/src/livarot/Shape.h \
		${WRKSRC}/src/object-edit.cpp \
		${WRKSRC}/src/spiral-context.cpp \
		${WRKSRC}/src/star-context.cpp
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|<stdint.h>|<sys/types.h>|g' \
		${WRKSRC}/src/livarot/*.h
	@${REINPLACE_CMD} -e 's|isfinite|!isinf|g' \
		${WRKSRC}/src/helper/*.cpp
.endif

.include <bsd.port.post.mk>

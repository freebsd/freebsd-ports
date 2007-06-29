# New ports collection makefile for:	inkscape
# Date created:		17 Nov 2003
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	inkscape
PORTVERSION=	0.45.1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program seeks to become a full featured open source SVG editor

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gc.1:${PORTSDIR}/devel/boehm-gc \
		gtkspell.0:${PORTSDIR}/textproc/gtkspell \
		lcms.1:${PORTSDIR}/graphics/lcms
RUN_DEPENDS=	${SITE_PERL}/XML/XQL.pm:${PORTSDIR}/textproc/p5-XML-XQL

#USE_BZIP2=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack desktopfileutils intlhack libxslt
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GCC=	3.4+
CONFIGURE_ARGS=	--with-popt \
		--mandir=${PREFIX}/man
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}"

MAN1=		inkscape.1
MAN1_EN=	inkview.1
MANLANG=	"" fr

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeprintui} != ""
USE_GNOME+=		libgnomeprintui
CONFIGURE_ARGS+=	--with-gnome-print
.else
CONFIGURE_ARGS+=	--without-gnome-print
.endif
.if ${HAVE_GNOME:Mgnomevfs2} != ""
USE_GNOME+=		gnomevfs2
CONFIGURE_ARGS+=	--with-gnome-vfs
.else
CONFIGURE_ARGS+=	--without-gnome-vfs
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|ieefp.h|ieeefp.h|' \
		${WRKSRC}/src/display/bezier-utils.cpp
	@${REINPLACE_CMD} -e 's|libpng >= 1.2|libpng12 >= 1.2|g' \
	    	${WRKSRC}/configure

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>

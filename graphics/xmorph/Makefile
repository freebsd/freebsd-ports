# New ports collection makefile for:    xmorph
# Date created:         Thu Aug  1 09:10:22 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xmorph
PORTVERSION=	2003.05.27
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/x/xmorph
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A digital image warping program

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//g}

CONFLICTS=	libmorph*

USE_X_PREFIX=	yes
WANT_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
INSTALLS_SHLIB=	yes

MAN1=		xmorph.1
INFO=		xmorph

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk20}!=""
USE_GNOME+=     gtk20
CONFIGURE_ARGS+=	--with-gtk2
MAN1+=		gtkmorph.1
PLIST_SUB+=	GTK2=""
.else
CONFIGURE_ARGS+=	--without-gtkmorph
PLIST_SUB+=	GTK2="@comment "
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/*.info*

.include <bsd.port.post.mk>

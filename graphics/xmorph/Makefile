# New ports collection makefile for:    xmorph
# Date created:         Thu Aug  1 09:10:22 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xmorph
PORTVERSION=	2004.01.10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A digital image warping program

WRKSRC=		${WRKDIR}/${PORTNAME}-current

CONFLICTS=	libmorph*

USE_X_PREFIX=	yes
WANT_GNOME=	yes
USE_GNOME=	gnometarget lthack
USE_INC_LIBTOOL_VER=	13
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
INSTALLS_SHLIB=	yes

MAN1=		xmorph.1
INFO=		xmorph

.include <bsd.port.pre.mk>

# XXX Seems that gtkmorph.1 is always installed
MAN1+=		gtkmorph.1
.if ${HAVE_GNOME:Mgtk20}!=""
USE_GNOME+=		gtk20
CONFIGURE_ARGS+=	--with-gtk2
.else
CONFIGURE_ARGS+=	--without-gtkmorph
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/*.info*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>

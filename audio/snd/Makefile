# New ports collection makefile for:	snd
# Date created:				2000-10-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		snd
PORTVERSION=		4.6
PORTREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		ftp://ccrma-ftp.stanford.edu/pub/Lisp/ \
			${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		trevor@FreeBSD.org

LIB_DEPENDS=		intl.1:${PORTSDIR}/devel/gettext

.if defined(WITHOUT_X)
WITHOUT_GTKEXTRA=	yes
.endif
.if !defined(WITHOUT_GTKEXTRA)
LIB_DEPENDS+=		gtkextra.14:${PORTSDIR}/x11-toolkits/gtkextra
.endif
.if !defined(WITHOUT_GUILE)
LIB_DEPENDS+=		guile.9:${PORTSDIR}/lang/guile
.if !defined(WITHOUT_X)
LIB_DEPENDS+=		guilegtk-1.2:${PORTSDIR}/x11-toolkits/guile-gtk
.endif
.endif

ALL_TARGET=		audinfo snd sndinfo sndplay sndrecord sndsine
CONFIGURE_ARGS=		--with-float-samples \
			--with-multifile
.if !defined(WITHOUT_X)
CONFIGURE_ARGS+=	--with-gtk \
			--with-gtkrc-colors \
			--with-float-samples
.endif
.if defined(WITHOUT_GUILE)
CONFIGURE_ARGS+=	--without-guile
.endif
.if !defined(WITHOUT_GTKEXTRA)
CONFIGURE_ARGS+=	--with-gtk-extra
.endif
.if defined(WITHOUT_X)
CONFIGURE_ARGS+=	--without-gui
.endif
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
GNU_CONFIGURE=	yes
MAKEFILE=	makefile
PLIST=		${WRKDIR}/pkg-plist
PREFIX=		/
.if !defined(WITHOUT_X)
USE_GLIB=	yes
USE_GTK=	yes
USE_XLIB=	yes
.endif
WRKSRC=		${WRKDIR}/snd-4

post-configure:
	@${PERL} -pi -e "s:^LIBS = :LIBS = -lm:g" ${WRKSRC}/makefile

do-install:
.for i in audinfo snd-info sndplay sndrecord sndsine
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${LOCALBASE}/bin
.endfor
.if !defined(WITHOUT_X)
	${INSTALL_PROGRAM} ${WRKSRC}/snd ${X11BASE}/bin
	${INSTALL_DATA} ${WRKSRC}/Snd.ad ${X11BASE}/lib/X11/app-defaults/
.else
	${INSTALL_PROGRAM} ${WRKSRC}/snd ${LOCALBASE}/bin
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${LOCALBASE}/share/doc/snd
	${RM} -f ${WRKSRC}/auto.png
.for i in COPYING HISTORY.Snd README.Snd
	${INSTALL_DATA} ${WRKSRC}/${i} ${LOCALBASE}/share/doc/snd
.endfor
	${INSTALL_DATA} \
		${WRKSRC}/*.html \
		${WRKSRC}/*.png \
		${WRKSRC}/*.txt \
		${LOCALBASE}/share/doc/snd
.if !defined(WITHOUT_GUILE)
	${INSTALL_DATA} ${WRKSRC}/*.scm ${LOCALBASE}/share/doc/snd
.endif
.endif

pre-build:
	${CP} ${PKGDIR}/pkg-plist-in ${PLIST}
.if !defined(WITHOUT_GUILE)
	${CAT} ${PKGDIR}/pkg-plist-guile >> ${PLIST}
.endif
.if !defined(WITHOUT_X)
	${ECHO} "%%X11BASE%%/bin/snd" >> ${PLIST}
	${ECHO} "%%X11BASE%%/lib/X11/app-defaults/Snd.ad" >> ${PLIST}
.else
	${ECHO} "%%LOCALBASE%%/bin/snd" >> ${PLIST}
.endif
.if !defined(NOPORTDOCS)
	${ECHO} "@dirrm %%LOCALBASE%%/share/doc/snd" >> ${PLIST}
.endif

post-build:
	${MV} ${WRKSRC}/sndinfo ${WRKSRC}/snd-info

.include <bsd.port.mk>

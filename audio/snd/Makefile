# New ports collection makefile for:	snd
# Date created:				2000-10-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		snd
PORTVERSION=		5.5
PORTREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		trevor@FreeBSD.org
COMMENT=		Multitracking sound editor and utilities

LIB_DEPENDS=		gsl.5:${PORTSDIR}/math/gsl

BROKEN=			"Does not compile"
DEPRECATED=		${BROKEN}
EXPIRATION_DATE=	2004-06-18

.if !defined(WITHOUT_ESD)
RUN_DEPENDS=		esd:${PORTSDIR}/audio/esound
.endif
.if !defined(WITHOUT_RUBY)
RUN_DEPENDS+=		ruby:${PORTSDIR}/lang/ruby16
.endif
.if defined(WITHOUT_X11)
WITHOUT_GTKEXTRA=	yes
.endif
.if !defined(WITHOUT_GTKEXTRA)
LIB_DEPENDS+=		gtkextra.17:${PORTSDIR}/x11-toolkits/gtkextra
.endif
.if !defined(WITHOUT_GUILE)
LIB_DEPENDS+=		guile.15:${PORTSDIR}/lang/guile
.if !defined(WITHOUT_X11)
LIB_DEPENDS+=		guilegtk-1.2:${PORTSDIR}/x11-toolkits/guile-gtk
.endif
.endif

ALL_TARGET=		audinfo snd sndinfo sndplay sndrecord sndsine
CONFIGURE_ARGS=		--with-float-samples \
			--with-multifile

.if !defined(WITHOUT_ESD)
CONFIGURE_ARGS+=	--with-esd
.endif
.if !defined(WITHOUT_RUBY)
CONFIGURE_ARGS+=	--with-ruby
.endif
.if !defined(WITHOUT_X11)
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
.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--with-no-gui
.endif

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS}"
MAKE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"

GNU_CONFIGURE=	yes
MAKEFILE=	makefile
PLIST=		${WRKDIR}/pkg-plist
.if !defined(WITHOUT_X11)
PREFIX=		${X11BASE}
USE_GETTEXT=	yes
USE_GNOME=	gtk12
USE_XLIB=	yes
.endif
WRKSRC=		${WRKDIR}/snd-5

post-configure:
	@${MV} ${WRKSRC}/makefile ${WRKSRC}/makefile.orig
	@${SED} -e "s: -ldl::g" < ${WRKSRC}/makefile.orig > ${WRKSRC}/makefile

pre-install:
	${ECHO_CMD} bin/snd > ${PLIST}
.if !defined(WITHOUT_X11)
	${ECHO_CMD} lib/X11/app-defaults/Snd.ad >> ${PLIST}
.endif
.for i in audinfo snd-info sndplay sndrecord sndsine
	${ECHO_CMD} bin/${i} >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
.for i in COPYING HISTORY.Snd README.Snd TODO.Snd
	${ECHO_CMD} share/doc/snd/${i} >> ${PLIST}
.endfor
	${FIND} ${WRKDIR} -name '*.html' | \
		${SED} -e "s:^${WRKSRC}/:share/doc/snd/:g" >> ${PLIST}
	${FIND} ${WRKDIR} -name '*.png' | \
		${SED} -e "s:^${WRKSRC}/:share/doc/snd/:g" >> ${PLIST}
	${ECHO_CMD} "@dirrm share/doc/snd" >> ${PLIST}
.endif
.if !defined(WITHOUT_GUILE)
	${FIND} ${WRKSRC} -name '*.scm' | \
		${SED} -e "s:^${WRKSRC}/:share/snd/:g" >> ${PLIST}
	${ECHO_CMD} "share/snd/contrib/dlp/README" >> ${PLIST}
	${ECHO_CMD} "@dirrm share/snd/contrib/dlp" >> ${PLIST}
	${ECHO_CMD} "@dirrm share/snd/contrib" >> ${PLIST}
	${ECHO_CMD} "@dirrm share/snd" >> ${PLIST}
.endif

do-install:
# Only "snd" is an X11 command.
.for i in audinfo snd snd-info sndplay sndrecord sndsine
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.if !defined(WITHOUT_X11)
	${INSTALL_DATA} ${WRKSRC}/Snd.ad ${PREFIX}/lib/X11/app-defaults/
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in COPYING HISTORY.Snd README.Snd TODO.Snd
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${INSTALL_DATA} \
		${WRKSRC}/*.html \
		${WRKSRC}/*.png \
		${DOCSDIR}
.if !defined(WITHOUT_GUILE)
	${MKDIR} ${DATADIR}/contrib/dlp
	${INSTALL_DATA} ${WRKSRC}/*.scm ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/*.scm ${DATADIR}/contrib/
	${INSTALL_DATA} ${WRKSRC}/contrib/dlp/* ${DATADIR}/contrib/dlp/
.endif
.endif

post-build:
	${MV} ${WRKSRC}/sndinfo ${WRKSRC}/snd-info

.include <bsd.port.mk>

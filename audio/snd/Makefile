# New ports collection makefile for:	snd
# Date created:				2000-10-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		snd
PORTVERSION=		7.8
PORTREVISION=	1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		trevor@FreeBSD.org
COMMENT=		Multitracking sound editor and utilities

LIB_DEPENDS=		gsl.6:${PORTSDIR}/math/gsl

ALL_TARGET=		audinfo snd sndinfo sndplay sndrecord sndsine
CONFIGURE_ARGS=		--with-float-samples \
			--with-multifile
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS}"
GNU_CONFIGURE=	yes
MAKE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"
MAKEFILE=	makefile
MAN1=		snd.1
OPTIONS=	ESD		"output through enlightened sound daemon" on \
		GUILE		"use Guile" on \
		RUBY		"use Ruby as the extension language" on
PLIST=		${WRKDIR}/plist
PLIST_FILES=	share/examples/snd/DotEmacs
PLIST_DIRS=	share/examples/snd
WRKSRC=		${WRKDIR}/snd-7

.if !defined(NOPORTDOCS)
PLIST_FILES+=	share/doc/snd/tutorial/files/.snd \
		share/doc/snd/tutorial/files/misc.scm.txt \
		share/doc/snd/tutorial/files/misc.scm.txt~ \
		share/doc/snd/tutorial/README \
		share/doc/snd/tutorial/1_intro_and_build_snd.html~
.endif

.if defined(WITH_ESD)
CONFIGURE_ARGS+=	--with-esd
RUN_DEPENDS=		esd:${PORTSDIR}/audio/esound
.endif

.if defined(WITH_RUBY)
CONFIGURE_ARGS+=	--with-ruby
RUN_DEPENDS+=		ruby:${PORTSDIR}/lang/ruby16
.endif

.if defined(WITH_GUILE)
LIB_DEPENDS+=		guile.15:${PORTSDIR}/lang/guile
.if !defined(WITHOUT_X11)
LIB_DEPENDS+=		guilegtk-1.2:${PORTSDIR}/x11-toolkits/guile-gtk
.endif
.else
CONFIGURE_ARGS+=	--without-guile
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_FILES+=	share/locale/de/LC_MESSAGES/snd.mo
.else
CONFIGURE_ARGS+=--disable-nls
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--with-no-gui
.else
CONFIGURE_ARGS+=	--with-gtk \
			--with-gtkrc-colors \
			--with-float-samples
USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_XLIB=	yes
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not build on sparc64"
.endif

post-build:
	${MV} ${WRKSRC}/sndinfo ${WRKSRC}/snd-info

pre-install:
.if !defined(WITHOUT_X11)
	${ECHO_CMD} lib/X11/app-defaults/Snd.ad >> ${PLIST}
	${ECHO_CMD} share/examples/snd/Snd.gtkrc >> ${PLIST}
.endif
.for i in audinfo snd snd-info sndplay sndrecord sndsine
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
	${FIND} ${WRKDIR} -name '*.jpg' | \
		${SED} -e "s:^${WRKSRC}/:share/doc/snd/:g" >> ${PLIST}
.for ii in	share/doc/snd/tutorial/images/jpg \
		share/doc/snd/tutorial/images \
		share/doc/snd/tutorial/files \
		share/doc/snd/tutorial \
		share/doc/snd
	${ECHO_CMD} @dirrm ${ii} >> ${PLIST}
.endfor
.endif
.if defined(WITH_GUILE)
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
	${INSTALL_MAN} ${WRKSRC}/snd.1 ${PREFIX}/man/man1/
.if !defined(WITHOUT_X11)
	${INSTALL_DATA} ${WRKSRC}/Snd.ad ${PREFIX}/lib/X11/app-defaults/
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in COPYING HISTORY.Snd README.Snd TODO.Snd
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/DotEmacs ${EXAMPLESDIR}
.if !defined(WITHOUT_X11)
	${INSTALL_DATA} ${WRKSRC}/Snd.gtkrc ${EXAMPLESDIR}
.endif
.if !defined(WITHOUT_NLS)
	${INSTALL_DATA} ${WRKSRC}/po/de.gmo \
		${PREFIX}/share/locale/de/LC_MESSAGES/snd.mo
.endif
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.png ${DOCSDIR}
	cd ${WRKSRC} && ${PAX} -r -w tutorial ${DOCSDIR}
.endif
.if defined(WITH_GUILE)
	${INSTALL_DATA} ${WRKSRC}/*.scm ${DATADIR}
.endif

.include <bsd.port.post.mk>

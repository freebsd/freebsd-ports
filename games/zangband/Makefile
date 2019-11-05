# Created by: Makoto YAMAKURA <makoto@pinpott.spnet.ne.jp>
# $FreeBSD$

PORTNAME=	zangband
DISTVERSION=	2.7.5pre1
CATEGORIES+=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION:R}%20preview%20I
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Zangband (Zelazny Angband) with color, X11 support

NO_CDROM=	Possible copyright infringement

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		autoreconf gmake localbase ncurses perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/lib \
		--with-gtk=no
MAKE_ENV=	VERBOSE=1
MAKEFILE=	makefile
ALL_TARGET=	default

SUB_FILES=	pkg-deinstall pkg-message
SUB_LIST=	ANGBANDBIN="${ANGBANDBIN}" ANGBANDLIB="${ANGBANDLIB}"

PLIST_SUB=	ANGBANDBIN="${ANGBANDBIN}" ANGBANDLIB="${ANGBANDLIB}"

OPTIONS_GROUP=		GUI
OPTIONS_GROUP_GUI=	TK X11

TK_USES=		tk
TK_CONFIGURE_ON=	--with-tcltk=${TCL_INCLUDEDIR} \
			--with-tkdir=${TK_INCLUDEDIR}
TK_CONFIGURE_OFF=	--with-tcltk=no
TK_LDFLAGS=		-lX11 -lXext
X11_USES=		xorg
X11_USE=		xorg=x11,xmu,xpm
X11_CONFIGURE_ENV=	ac_cv_lib_Xm_main=no
X11_CONFIGURE_OFF=	--with-x11=no

ANGBANDBIN?=	bin/${PORTNAME}
ANGBANDLIB?=	lib/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e \
		's|tcl84|tcl86|g ; \
		 s|tcl8.4|tcl8.6|g ; \
		 s|tcl83|tcl85|g ; \
		 s|tcl8.3|tcl8.5|g ; \
		 s|tk84|tk86|g ; \
		 s|tk8.4|tk8.6|g ; \
		 s|tk83|tk85|g ; \
		 s|tk8.3|tk8.5|g ; \
		 s|/usr/local/include|${LOCALBASE}/include|g ; \
		 s| $${!FLAG} = yes| x$${FLAG} != xno|' \
		${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e \
		's|$$(datadir)/games|$$(datadir)| ; \
		 s|$$(DESTDIR)lib/|$$(DESTDIR)|' \
		${WRKSRC}/makefile.in
	@${ECHO_CMD} -n > ${WRKSRC}/.version

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} zangband \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ANGBANDLIB}
	(cd ${WRKSRC}/lib && ${FIND} . ! -name "makefile.zb" \
		-a ! -name "*.bak" -a ! -name "*.orig" | \
		${CPIO} -dump -L ${STAGEDIR}${PREFIX}/${ANGBANDLIB})

.include <bsd.port.mk>

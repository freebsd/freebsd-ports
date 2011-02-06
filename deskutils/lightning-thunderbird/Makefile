# New ports collection makefile for:	sunbird
# Date created:		2005-02-26
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lightning
DISTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	calendar/${PORTNAME}/releases/${DISTVERSION}b2/source
PKGNAMESUFFIX=	-thunderbird
DISTNAME=	${PORTNAME}-${DISTVERSION}b2.source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	An integrated calendar for Thunderbird 3.1

RUN_DEPENDS+=	${LOCALBASE}/lib/thunderbird/thunderbird-bin:${PORTSDIR}/mail/thunderbird

CONFLICTS_BUILD=	spidermonkey-1.[0-7]*
USE_AUTOTOOLS=	autoconf213 libtool
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
MAKE_ENV=		PTHREAD_LDFLAGS="${PTHREAD_LIBS}"
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GECKO=	gecko
MAKE_JOBS_SAFE=	yes
WANT_GNOME=	yes
WANT_PERL=	yes
USE_MOZILLA=	-png -dbm -jpeg -xft
MOZ_TOOLKIT=	cairo-gtk2
LIBS=		-Wl,-Bsymbolic -lc
MOZ_PKGCONFIG_FILES=	${PORTNAME}-js ${PORTNAME}-xpcom ${PORTNAME}-plugin
PKGCONFIG_FILES=	${MOZ_PKG_CONFIG_FILES}
MOZ_OPTIONS=	--enable-application=calendar \
		--enable-system-cairo --disable-updater \
		--enable-canvas --disable-necko-wifi
MOZ_MK_OPTIONS=	MOZ_CO_PROJECT=calendar
NOGECKO_PLIST=		yes
NOGECKO_INSTALL=	yes

.include <bsd.init.mk>
.include <bsd.libnames.mk>
.include <bsd.port.pre.mk>

XPI_FILE=	${DISTNAME:C/.source//}-freebsd${OSVERSION:C/([0-9]).+/\1/}-${ARCH}.xpi
PLIST_FILES=	%%DATADIR%%/${XPI_FILE}
PLIST_DIRS=	%%DATADIR%%

WRKSRC=		${WRKDIR}/comm-1.9.2
MOZSRC:=	${WRKSRC}/mozilla

.if ${OSVERSION} < 700000
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
EXTRA_PATCHES=	${FILESDIR}/releng6_pulseaudio
.else
EXTRA_PATCHES=	${FILESDIR}/liboggplay_oss
.endif

GECKO_PTHREAD_LIBS!=${CC} -dumpspecs | ${GREP} -m 1 '%{\!pg: %{pthread:' | ${SED} -e 's|^.*%{\!pg: %{pthread:|| ; s|}.*$$||' || ${TRUE}

.if defined(WITHOUT_DBUS)
MOZ_OPTIONS+=	--disable-dbus --disable-libnotify
.else
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		notify.1:${PORTSDIR}/devel/libnotify
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:C/-pthread/${GECKO_PTHREAD_LIBS}/}|' \
		${MOZSRC}/storage/build/Makefile.in \
		${MOZSRC}/db/sqlite3/src/Makefile.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${MOZSRC}/security/manager/ssl/src/Makefile.in \
		${MOZSRC}/js/src/config/mkdepend/Makefile.in \
		${MOZSRC}/js/src/config/config.mk
	@${REINPLACE_CMD} -e 's|%%LIB_BZ2%%|${LIBBZ2}|' \
		${MOZSRC}/toolkit/mozapps/update/src/updater/Makefile.in
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g ; \
		s|echo aout|echo elf|g ; \
		s|/usr/X11R6|${LOCALBASE}|g' \
		${MOZSRC}/js/src/configure \
		${MOZSRC}/configure

pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${MOZSRC} && ${AUTOCONF})
	(cd ${MOZSRC}/js/src/ && ${AUTOCONF})

post-build:
	@(cd ${MOZSRC}/xpfe/components/autocomplete/src && ${GMAKE})

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${MOZSRC}/dist/xpi-stage/${PORTNAME}.xpi ${DATADIR}/${XPI_FILE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

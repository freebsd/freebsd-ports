# New ports collection makefile for:	libstatgrab
# Date created:		30 March 2003
# Whom:			Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	libstatgrab
PORTVERSION=	0.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.mirror.ac.uk/sites/ftp.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://www.mirror.ac.uk/sites/ftp.i-scream.org/pub/i-scream/%SUBDIR%/ \
		ftp://ftp.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://www.i-scream.org/pub/i-scream/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tim@bishnet.net
COMMENT=	Provides a useful interface to system statistics

DIST_SUBDIR=	i-scream
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes

MAN3=		cpu_percent_usage.3 get_cpu_diff.3 get_cpu_totals.3 \
		get_diskio_stats.3 get_diskio_stats_diff.3 get_general_stats.3 \
		get_load_stats.3 get_memory_stats.3 get_network_stats.3 \
		get_network_stats_diff.3 get_page_stats.3 \
		get_page_stats_diff.3 get_process_stats.3 get_swap_stats.3 \
		get_user_stats.3 statgrab.3

CONFIGURE_ARGS+=	--disable-examples \
			--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig

.if defined(WITHOUT_STATGRAB)
CONFIGURE_ARGS+=	--disable-statgrab
PLIST_SUB+=		STATGRAB="@comment "
.else
PLIST_SUB+=		STATGRAB=""
.endif

.if defined(WITHOUT_SAIDAR)
CONFIGURE_ARGS+=	--disable-saidar
PLIST_SUB+=		SAIDAR="@comment "
.else
PLIST_SUB+=		SAIDAR=""
.endif

.if defined(WITHOUT_SETGID_BINARIES)
CONFIGURE_ARGS+=	--disable-setgid-binaries
.endif

.include <bsd.port.mk>

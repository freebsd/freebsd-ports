# New ports collection makefile for:	distcc
# Date created:				25 June 2002
# Whom:					Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#   $MCom: ports/devel/distcc/Makefile,v 1.3 2007/10/21 02:46:13 ahze Exp $
#

PORTNAME=	distcc
PORTVERSION=	2.18.3
PORTREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	http://distcc.samba.org/ftp/distcc/
#PATCH_SITES=	http://0pointer.de/public/
PATCH_SITES=	${MASTER_SITES_LOCAL}
PATCH_SITE_SUBDIR=	ahze

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Distribute compilation of C(++) code acrosss machines on a network

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	 --enable-rfc2553
WANT_GNOME=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
DISTCCD_PIDFILE=/var/run/distccd.pid
USE_RC_SUBR=	distccd.sh
SUB_LIST=	DISTCCD_PIDFILE=${DISTCCD_PIDFILE}

OPTIONS=	AVAHI   "Enable Avahi Zeroconf/mDNS/Bonjour support" Off \
		GNOME	"Build GUI monitor based on GNOME"	Off \
		GTK	"Build GUI monitor based on GTK"	Off \
		COMPILER_LINKS	"Create symlinks to distcc"	On

.include <bsd.port.pre.mk>

.if defined(WITH_AVAHI)
PATCHFILES+=	distcc-avahi-080101.patch
LIB_DEPENDS+=	avahi-glib.1:${PORTSDIR}/net/avahi-app
PATCH_DIST_STRIP=	-p1
USE_AUTOTOOLS+=	autoconf:262
AUTOCONF_ARGS+=	-I${LOCALBASE}/share/libtool/libltdl/
CFLAGS+=	-DHAVE_AVAHI
.endif

.if defined(WITH_COMPILER_LINKS)
CCLINKDIR?=		libexec/distcc
PLIST_DIRS=		${CCLINKDIR}
GNU_COMPILERS=		34 42 43 44 -ooo
DISTCC_COMPILERS=	cc c++ gcc g++ ${GNU_COMPILERS:S|^|gcc|} ${GNU_COMPILERS:S|^|g++|}
.if ${ARCH} == "i386"
DISTCC_COMPILERS+=	icc icpc
.endif
.if defined(EXTRA_COMPILERS)
DISTCC_COMPILERS+=	${EXTRA_COMPILERS}
.endif
PLIST_FILES+=		${DISTCC_COMPILERS:S|^|${CCLINKDIR}/|}
.endif

.if defined(WITH_GNOME)
USE_GNOME=		libgnomeui
CONFIGURE_ARGS+=	--with-gnome
PKGNAMESUFFIX=		-gnome
PLIST_SUB+=		WITH_GNOME=""
.elif defined(WITH_GTK)
USE_GNOME=		gtk20
CONFIGURE_ARGS+=	--with-gtk
PKGNAMESUFFIX=		-gtk
PLIST_SUB+=		WITH_GNOME=""
.else
PLIST_SUB+=		WITH_GNOME="@comment "
.endif

MAN1=		distcc.1 distccd.1
DOC_FILES=	AUTHORS INSTALL NEWS README \
		doc/protocol-1.txt doc/status-1.txt \
		doc/protocol-2.txt doc/reporting-bugs.txt

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/distcc ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/distccmon-text ${PREFIX}/bin
.if defined(WITH_GNOME) || defined(WITH_GTK)
	@${INSTALL_PROGRAM} ${WRKSRC}/distccmon-gnome ${PREFIX}/bin
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/distccd ${PREFIX}/sbin

post-install:
	@${TOUCH} ${DISTCCD_PIDFILE}
.if defined(WITH_COMPILER_LINKS)
	@${MKDIR} ${PREFIX}/${CCLINKDIR}
.for link in ${DISTCC_COMPILERS}
	${LN} -sf ${PREFIX}/bin/distcc ${PREFIX}/${CCLINKDIR}/${link}
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif
.for f in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/man/${f} ${MANPREFIX}/man/man1
.endfor
	@${CAT} ${PKGMESSAGE}
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>

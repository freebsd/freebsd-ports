# Created by: Frerich Raabe <frerich.raabe@gmx.de>
# $FreeBSD$
#   $MCom: ports/devel/distcc/Makefile,v 1.3 2007/10/21 02:46:13 ahze Exp $

PORTNAME=	distcc
PORTVERSION=	3.1
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Distribute compilation of C(++) code acrosss machines on a network

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gprof --disable-Werror
WANT_GNOME=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_RC_SUBR=	distccd

OPTIONS_DEFINE=	GNOME GTK IPV6 AVAHI COMPILER_LINKS DOCS
GNOME_DESC=	GUI monitor based on GNOME
GTK_DESC=	Build GUI monitor based on GTK
AVAHI_DESC=	Avahi Zeroconf/mDNS/Bonjour support
COMPILER_LINKS=	Create symlinks to distcc

OPTIONS_DEFAULT=	COMPILER_LINKS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	libavahi-glib.1.so:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=	--without-avahi
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-rfc2553
.else
CONFIGURE_ARGS+=	--disable-rfc2553
.endif

.if ${PORT_OPTIONS:MCOMPILER_LINKS}
CCLINKDIR?=		libexec/distcc
PLIST_DIRS=		${CCLINKDIR}
GNU_COMPILERS=		34 42 43 44 45 46 47 48 -ooo
DISTCC_COMPILERS=	cc c++ gcc g++ ${GNU_COMPILERS:S|^|gcc|} ${GNU_COMPILERS:S|^|g++|}
DISTCC_COMPILERS+=	clang clang++ llvm-gcc llvm-c++ llvm-g++
.if ${ARCH} == "i386"
DISTCC_COMPILERS+=	icc icpc
.endif
.if defined(EXTRA_COMPILERS)
DISTCC_COMPILERS+=	${EXTRA_COMPILERS}
.endif
PLIST_FILES+=		${DISTCC_COMPILERS:S|^|${CCLINKDIR}/|}
.endif

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME=		libgnomeui
CONFIGURE_ARGS+=	--with-gnome
PKGNAMESUFFIX=		-gnome
PLIST_SUB+=		WITH_GNOME=""
.elif ${PORT_OPTIONS:MGTK}
USE_GNOME=		gtk20
CONFIGURE_ARGS+=	--with-gtk
PKGNAMESUFFIX=		-gtk
PLIST_SUB+=		WITH_GNOME=""
.else
PLIST_SUB+=		WITH_GNOME="@comment "
.endif

DOC_FILES=	AUTHORS INSTALL NEWS README \
		doc/protocol-1.txt doc/status-1.txt \
		doc/protocol-2.txt doc/reporting-bugs.txt

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/distcc ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/distccmon-text ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/lsdistcc ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MGNOME} || ${PORT_OPTIONS:MGTK}
	@${INSTALL_PROGRAM} ${WRKSRC}/distccmon-gnome ${STAGEDIR}${PREFIX}/bin
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/distccd ${STAGEDIR}${PREFIX}/sbin

post-install:
.if ${PORT_OPTIONS:MCOMPILER_LINKS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${CCLINKDIR}
.for link in ${DISTCC_COMPILERS}
	${LN} -sf ${PREFIX}/bin/distcc ${STAGEDIR}${PREFIX}/${CCLINKDIR}/${link}
.endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
.for man in distcc.1 distccd.1 distccmon-text.1
	${INSTALL_MAN} ${WRKSRC}/man/${man} ${STAGEDIR}${MANPREFIX}/man/man1
.endfor
	@${CAT} ${PKGMESSAGE}
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>

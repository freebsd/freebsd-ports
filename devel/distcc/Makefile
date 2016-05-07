# Created by: Frerich Raabe <frerich.raabe@gmx.de>
# $FreeBSD$
#   $MCom: ports/devel/distcc/Makefile,v 1.3 2007/10/21 02:46:13 ahze Exp $

PORTNAME=	distcc
PORTVERSION=	3.1
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distribute compilation of C(++) code acrosss machines on a network

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt

GNU_CONFIGURE=	yes
USES=		alias gmake tar:bzip2
WANT_GNOME=	yes

GROUPS=		distcc
USERS=		distcc

CCLINKDIR?=	libexec/distcc
CONFIGURE_ARGS=	--disable-Werror
CONFIGURE_ENV=	PYTHON="${NONEXISTENT}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message
SUB_LIST=	DISTCCD_PIDFILE=/var/run/distccd.pid
USE_RC_SUBR=	distccd

BIN_FILES=	distcc distccmon-text lsdistcc
DOC_FILES=	protocol-1.txt status-1.txt \
		protocol-2.txt reporting-bugs.txt
MAN_FILES=	distcc.1 distccd.1 distccmon-text.1
README_FILES=	AUTHORS INSTALL NEWS README
SBIN_FILES=	distccd

PLIST_FILES=	${BIN_FILES:S|^|bin/|}
PLIST_FILES+=	${DISTCC_COMPILERS:S|^|${CCLINKDIR}/|}
PLIST_FILES+=	${MAN_FILES:S|^|man/man1/|:S|$|.gz|}
PLIST_FILES+=	${SBIN_FILES:S|^|sbin/|}

OPTIONS_DEFINE=	AVAHI CLANGLINK DOCS IPV6 LLVMLINK
OPTIONS_RADIO=	GUI
OPTIONS_RADIO_GUI=	GNOME GTK

CLANGLINK_DESC=	Create clang compiler links if clang is installed
GUI_DESC=	Build GUI for distcc monitor
GNOME_DESC=	Monitor based on GNOME
GTK_DESC=	Monitor based on GTK
LLVMLINK_DESC=	Create llvm compiler links if llvm is installed

AVAHI_CONFIGURE_WITH=	avahi
AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
DOCS_PLIST_FILES=	${README_FILES:S|^|${DOCSDIR_REL}/|}
DOCS_PLIST_FILES+=	${DOC_FILES:S|^|${DOCSDIR_REL}/|}
GNOME_CONFIGURE_WITH=	gnome
GNOME_USE=	GNOME=gtk20,libgnome,libgnomeui,pango
GTK_CONFIGURE_WITH=	gtk
GTK_USE=	GNOME=gtk20
IPV6_CONFIGURE_ENABLE=	rfc2553

DISTCC_COMPILERS=	CC c++ cc

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLANGLINK}
CLANG_COMPILERS=	-devel 31 32 33 34 35
DISTCC_COMPILERS+=	clang++ clang
DISTCC_COMPILERS+=	${CLANG_COMPILERS:S|^|clang++|}
DISTCC_COMPILERS+=	${CLANG_COMPILERS:S|^|clang|}
.endif
GNU_COMPILERS=		34 42 43 44 45 46 47 48 49 5
DISTCC_COMPILERS+=	gcc g++
DISTCC_COMPILERS+=	${GNU_COMPILERS:S|^|g++|}
DISTCC_COMPILERS+=	${GNU_COMPILERS:S|^|gcc|}
.if ${ARCH} == "i386"
DISTCC_COMPILERS+=	icc icpc
.endif
.if ${PORT_OPTIONS:MLLVMLINK}
DISTCC_COMPILERS+=	llvm-c++ llvm-g++ llvm-gcc
.endif
DISTCC_COMPILERS+=	${EXTRA_COMPILERS}

.if ${PORT_OPTIONS:MGNOME} || ${PORT_OPTIONS:MGTK}
.if ${PORT_OPTIONS:MGNOME}
PKGNAMESUFFIX=	-gnome
.else
PKGNAMESUFFIX=	-gtk
.endif
BIN_FILES+=	distccmon-gnome
PLIST_FILES+=	${DESKTOPDIR}/distccmon-gnome.desktop
PLIST_FILES+=	share/pixmaps/distccmon-gnome-icon.png
.endif

.if ${PORT_OPTIONS:MGNOME} || ${PORT_OPTIONS:MGTK}
post-patch:
	${REINPLACE_CMD} -e 's|PKGDATADIR "|"${PREFIX}/share/pixmaps|' \
	    ${WRKSRC}/src/mon-gnome.c
.endif

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${BIN_FILES} \
	    ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${SBIN_FILES} \
	    ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${PREFIX}/${CCLINKDIR}
.for link in ${DISTCC_COMPILERS}
	${LN} -sf ${PREFIX}/bin/distcc \
	    ${STAGEDIR}${PREFIX}/${CCLINKDIR}/${link}
.endfor
.if ${PORT_OPTIONS:MGNOME} || ${PORT_OPTIONS:MGTK}
	cd ${WRKSRC}/gnome && ${INSTALL_DATA} distccmon-gnome.desktop \
	    ${STAGEDIR}${DESKTOPDIR}
	cd ${WRKSRC}/gnome && ${INSTALL_DATA} distccmon-gnome-icon.png \
	    ${STAGEDIR}${PREFIX}/share/pixmaps
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${README_FILES} \
	    ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${DOC_FILES} \
	    ${STAGEDIR}${DOCSDIR}
.endif
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN_FILES} \
	    ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>

# Created by: Frerich Raabe <frerich.raabe@gmx.de>
# $FreeBSD$
#   $MCom: ports/devel/distcc/Makefile,v 1.3 2007/10/21 02:46:13 ahze Exp $

PORTNAME=	distcc
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.5
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distribute compilation of C(++) code across machines on a network

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libiberty.a:devel/gnulibiberty
LIB_DEPENDS=	libpopt.so:devel/popt

USES=		alias autoreconf gmake libtool localbase pkgconfig
USE_GITHUB=	yes
USE_RC_SUBR=	distccd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-Werror \
		--sysconfdir=${ETCDIR} \
		CC="${CC}" \
		PTHREAD_CC="${CC}"

TEST_TARGET=	check

ETCDIR=		${PREFIX}/etc

SUB_FILES=	pkg-message
SUB_LIST=	DISTCCD_PIDFILE=/var/run/distccd.pid

USERS=		distcc
GROUPS=		distcc

PLIST_FILES=	${_BIN_FILES:S|^|bin/|} \
		${_CONFIG_FILES:S|^|${ETCDIR}/${PORTNAME}/|} \
		${_DISTCC_COMPILERS:S|^|${CCLINKDIR}/|} \
		${_MAN_FILES:S|^|man/man1/|:S|$|.gz|} \
		${_SBIN_FILES:S|^|sbin/|} \
		etc/default/distcc

OPTIONS_DEFINE=		AVAHI CLANGLINK DOCS IPV6 LLVMLINK PUMP
OPTIONS_RADIO=		GUI
OPTIONS_RADIO_GUI=	GNOME GTK

CLANGLINK_DESC=	Create clang compiler links if clang is installed
GNOME_DESC=	Monitor based on GNOME
GTK_DESC=	Monitor based on GTK
GUI_DESC=	Build GUI for distcc monitor
LLVMLINK_DESC=	Create llvm compiler links if llvm is installed
PUMP_DESC=	Distribute compilation as well as preprocessing to distcc servers

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CONFIGURE_WITH=	avahi
DOCS_PLIST_FILES+=	${_DOC_FILES:S|^|${DOCSDIR_REL}/|} \
			${_README_FILES:S|^|${DOCSDIR_REL}/|}
GNOME_USES=		gnome
GNOME_USE=		GNOME=gtk20,libgnome,libgnomeui,pango
GNOME_CONFIGURE_WITH=	gnome
GTK_USES=		gnome
GTK_USE=		GNOME=gtk20
GTK_CONFIGURE_WITH=	gtk
IPV6_CONFIGURE_ENABLE=	rfc2553
PUMP_USES=		python:3.1+
PUMP_CONFIGURE_ENABLE=	pump-mode
PUMP_PLIST_FILES=	${PYTHON_SITELIBDIR}/include_server-${PORTVERSION}-py${PYTHON_VER}.egg-info \
			${PYTHON_SITELIBDIR}/include_server/basics.py \
			${PYTHON_SITELIBDIR}/include_server/basics_test.py \
			${PYTHON_SITELIBDIR}/include_server/c_extensions_test.py \
			${PYTHON_SITELIBDIR}/include_server/cache_basics.py \
			${PYTHON_SITELIBDIR}/include_server/compiler_defaults.py \
			${PYTHON_SITELIBDIR}/include_server/compress_files.py \
			${PYTHON_SITELIBDIR}/include_server/distcc_pump_c_extensions.so \
			${PYTHON_SITELIBDIR}/include_server/include_analyzer.py \
			${PYTHON_SITELIBDIR}/include_server/include_analyzer_memoizing_node.py \
			${PYTHON_SITELIBDIR}/include_server/include_analyzer_memoizing_node_test.py \
			${PYTHON_SITELIBDIR}/include_server/include_analyzer_test.py \
			${PYTHON_SITELIBDIR}/include_server/include_server.py \
			${PYTHON_SITELIBDIR}/include_server/include_server_test.py \
			${PYTHON_SITELIBDIR}/include_server/macro_eval.py \
			${PYTHON_SITELIBDIR}/include_server/macro_eval_test.py \
			${PYTHON_SITELIBDIR}/include_server/mirror_path.py \
			${PYTHON_SITELIBDIR}/include_server/mirror_path_test.py \
			${PYTHON_SITELIBDIR}/include_server/parse_command.py \
			${PYTHON_SITELIBDIR}/include_server/parse_command_test.py \
			${PYTHON_SITELIBDIR}/include_server/parse_file.py \
			${PYTHON_SITELIBDIR}/include_server/parse_file_test.py \
			${PYTHON_SITELIBDIR}/include_server/run.py \
			${PYTHON_SITELIBDIR}/include_server/setup.py \
			${PYTHON_SITELIBDIR}/include_server/statistics.py

# Leave CCLINKDIR without a leading underscore as it is a variable, which could
# be set by the user.
CCLINKDIR?=		libexec/distcc
_DISTCC_COMPILERS=	CC c++ cc

_CONFIG_FILES=	clients.allow commands.allow.sh hosts
_BIN_FILES=	distcc distccmon-text lsdistcc
_DOC_FILES=	protocol-1.txt protocol-2.txt protocol-3.txt \
		protocol-3-impl.txt protocol-gssapi.txt reporting-bugs.txt \
		status-1.txt survey.txt
_MAN_FILES=	distcc.1 distccd.1 distccmon-text.1 include_server.1 lsdistcc.1 \
		pump.1
_README_FILES=	AUTHORS COPYING INSTALL NEWS README README.pump TODO
_SBIN_FILES=	distccd

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLANGLINK}
CLANG_COMPILERS=	-devel 31 32 33 34 35 36 37 38 39
_DISTCC_COMPILERS+=	clang++ clang ${CLANG_COMPILERS:S|^|clang++|} \
			${CLANG_COMPILERS:S|^|clang|}
.endif
GNU_COMPILERS=		34 42 43 44 45 46 47 48 49 5
_DISTCC_COMPILERS+=	gcc g++ ${GNU_COMPILERS:S|^|g++|} \
			${GNU_COMPILERS:S|^|gcc|}
.if ${ARCH} == "i386"
_DISTCC_COMPILERS+=	icc icpc
.endif
.if ${PORT_OPTIONS:MLLVMLINK}
_DISTCC_COMPILERS+=	llvm-c++ llvm-g++ llvm-gcc
.endif
_DISTCC_COMPILERS+=	${EXTRA_COMPILERS}

.if ${PORT_OPTIONS:MGNOME} || ${PORT_OPTIONS:MGTK}
.if ${PORT_OPTIONS:MGNOME}
PKGNAMESUFFIX=	-gnome
.else
PKGNAMESUFFIX=	-gtk
.endif
_BIN_FILES+=	distccmon-gnome
PLIST_FILES+=	${DESKTOPDIR}/distccmon-gnome.desktop \
		share/pixmaps/distccmon-gnome-icon.png
.endif

.if ${PORT_OPTIONS:MGNOME} || ${PORT_OPTIONS:MGTK}
post-patch:
	${REINPLACE_CMD} -e 's|PKGDATADIR "|"${PREFIX}/share/pixmaps|' \
	    ${WRKSRC}/src/mon-gnome.c
.endif

.if ${PORT_OPTIONS:MPUMP}
_BIN_FILES+=	pump
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${CCLINKDIR}
.for link in ${_DISTCC_COMPILERS}
	@${LN} ${STAGEDIR}${PREFIX}/bin/distcc \
	    ${STAGEDIR}${PREFIX}/${CCLINKDIR}/${link}
.endfor
	${RM} -rf ${STAGEDIR}${PYTHON_SITELIBDIR}/*/__pycache__
	${RM} -rf ${STAGEDIR}${PREFIX}/${DOCSDIR_REL}/example

post-install-PUMP-on:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/include_server/distcc_pump_c_extensions.so

post-install-PUMP-off:
	${RM} ${STAGEDIR}${PUMP_PLIST_FILES}
	${RM} ${STAGEDIR}/bin/pump

.include <bsd.port.mk>

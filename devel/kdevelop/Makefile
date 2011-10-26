# New ports collection makefile for:	kdevelop
# Date created:		12 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kdevelop
PORTVERSION=	3.5.4
PORTREVISION=	7
CATEGORIES?=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${KDE_VERSION}/src
# DISTNAME=	${KDE_DISTNAME}
DIST_SUBDIR=	KDE

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	IDE for a wide variety of programming tasks

BUILD_DEPENDS=	cervisia:${PORTSDIR}/devel/kdesdk3 \
		dot:${PORTSDIR}/graphics/graphviz
LIB_DEPENDS=	svn_client-1.0:${PORTSDIR}/devel/subversion16
RUN_DEPENDS=	${LOCALBASE}/share/autotools:${PORTSDIR}/devel/autotools \
		extractrc:${PORTSDIR}/devel/kdesdk3 \
		gdb66:${PORTSDIR}/devel/gdb66 \
		gmake:${PORTSDIR}/devel/gmake

BROKEN=		conflicting dependencies

CONFLICTS_BUILD=subversion-1.7.[0-9]*

.if defined(WITH_OPTIONAL_DEPENDS)

PAPERSIZE?=	letter

.if ${PAPERSIZE} != a4 && ${PAPERSIZE} != letter && ${PAPERSIZE} != letterdj
.BEGIN:
	@${ECHO_CMD}
	@${ECHO_CMD} "PAPERSIZE incorrect value: ${PAPERSIZE}."
	@${ECHO_CMD}
	@${ECHO_CMD} "Must specify PAPERSIZE as one of a4, letter, or letterdj."
	@${ECHO_CMD} "letterdj allows a slightly larger margins for DeskJets."
	@${FALSE}
.endif

RUN_DEPENDS+=	ark:${PORTSDIR}/misc/kdeutils3 \
		a2ps:${PORTSDIR}/print/a2ps-${PAPERSIZE} \
		dot:${PORTSDIR}/graphics/graphviz \
		glimpse:${PORTSDIR}/textproc/glimpse \
		kiconedit:${PORTSDIR}/graphics/kdegraphics3
.endif

# KDE_DISTNAME=		${PORTNAME}-${PORTVERSION}_for_KDE_3.1

USE_LDCONFIG=	yes
USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	build
USE_BDB=	yes
USE_AUTOTOOLS=	libtool
_NO_KDE_FINAL=	yes
CONFIGURE_ARGS+=--with-qtdoc-dir=${LOCALBASE}/share/doc/qt/html \
		--with-db-includedir=${BDB_INCLUDE_DIR} \
		--with-db-libdir=${BDB_LIB_DIR} --with-db-lib=${BDB_LIB_NAME} \
		--with-apr-config=${LOCALBASE}/bin/apr-1-config \
		--with-apu-config=${LOCALBASE}/bin/apu-1-config \
		--with-svn-include=${LOCALBASE}/include/subversion-1 \
		--with-svn-lib=${LOCALBASE}/lib \
		--with-neon-config=${LOCALBASE}/bin/neon-config

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WITH_OPTIONAL_DEPENDS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You may define WITH_OPTIONAL_DEPENDS (make WITH_OPTIONAL_DEPENDS=YES)"
	@${ECHO_MSG} "to automatically build the suggested programs to complement kdevelop."
	@${ECHO_MSG}
.endif

post-patch:
	@${TOUCH} -t 200401230000 ${WRKSRC}/Makefile.am.in
	@${CP} ${WRKSRC}/admin/acinclude.m4.in ${WRKSRC}/parts/appwizard/common/admin/acinclude.m4.in

post-configure:
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' < ${FILESDIR}/kdevelop \
		> ${WRKDIR}/kdevelop
	${REINPLACE_CMD} -e 's|<gdbpath>.*</gdbpath>|<gdbpath></gdbpath>|g' \
		-e 's|<dbgshell>.*</dbgshell>|<dbgshell></dbgshell>|g' \
		${WRKSRC}/languages/cpp/app_templates/*/*.kdevelop
	${REINPLACE_CMD} -e 's|"gdb"|"gdb66"|g' \
		${WRKSRC}/languages/cpp/debugger/gdbcontroller.cpp
	${REINPLACE_CMD} -E -e 's|(.*shell =.*)libtool|\1libtool --mode=execute|g' \
		${WRKSRC}/languages/cpp/debugger/debuggerconfigwidget.cpp

post-install:
	@${MV} ${PREFIX}/bin/kdevelop ${PREFIX}/bin/kdevelop-bin
	@${INSTALL_SCRIPT} ${WRKDIR}/kdevelop ${PREFIX}/bin

.include <bsd.port.post.mk>

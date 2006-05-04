# New ports collection makefile for:	kdevelop
# Date created:		12 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kdevelop
PORTVERSION=	3.3.2
CATEGORIES?=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${KDE_VERSION:S/.0//}/src
# DISTNAME=	${KDE_DISTNAME}
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org
COMMENT=	IDE for a wide variety of programming tasks

BUILD_DEPENDS=	cervisia:${PORTSDIR}/devel/kdesdk3 \
		msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4 \
		svn_client-1.0:${PORTSDIR}/devel/subversion
RUN_DEPENDS=	extractrc:${PORTSDIR}/devel/kdesdk3 \
		gmake:${PORTSDIR}/devel/gmake \
		${LOCALBASE}/gnu-autotools/bin/automake:${PORTSDIR}/devel/gnu-automake \
		${LOCALBASE}/gnu-autotools/bin/autoconf:${PORTSDIR}/devel/gnu-autoconf \
		${LOCALBASE}/gnu-autotools/bin/libtool:${PORTSDIR}/devel/gnu-libtool

.if defined(WITH_OPTIONAL_DEPENDS)
RUN_DEPENDS+=	kiconedit:${PORTSDIR}/graphics/kdegraphics3 \
		ark:${PORTSDIR}/misc/kdeutils3 \
		glimpse:${PORTSDIR}/textproc/glimpse \
		a2ps:${PORTSDIR}/print/a2ps-letter
.endif

# KDE_DISTNAME=		${PORTNAME}-${PORTVERSION}_for_KDE_3.1

INSTALLS_SHLIB=	yes
USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=  libtool:15
CONFIGURE_ARGS+=--with-qtdoc-dir=${X11BASE}/share/doc/qt/html \
		--with-db-includedir=${LOCALBASE}/include/db4 \
		--with-db-libdir=${LOCALBASE}/lib --with-db-lib=db4 \
		--with-apr-config=${LOCALBASE}/bin/apr-1-config \
		--with-apu-config=${LOCALBASE}/bin/apu-1-config \
		--with-subversion-dir=${LOCALBASE} \
		--with-svn-include=${LOCALBASE}/include \
		--with-svn-lib=${LOCALBASE}/lib \
		--with-neon-config=${LOCALBASE}/bin/neon-config

CONFIGURE_ENV+=	PATH=${LOCALBASE}/gnu-autotools/bin:${PATH}

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

post-install:
	@${MV} ${PREFIX}/bin/kdevelop ${PREFIX}/bin/kdevelop-bin
	@${INSTALL_SCRIPT} ${WRKDIR}/kdevelop ${PREFIX}/bin

.include <bsd.port.post.mk>

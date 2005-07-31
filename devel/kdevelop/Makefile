# New ports collection makefile for:	kdevelop
# Date created:		12 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kdevelop
PORTVERSION=	3.2.2
CATEGORIES?=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${KDE_VERSION:S/.0//}/src
# DISTNAME=	${KDE_DISTNAME}
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org
COMMENT=	Powerful IDE for developing KDE/Qt-based apps

BUILD_DEPENDS=	cervisia:${PORTSDIR}/devel/kdesdk3 \
		msgfmt:${PORTSDIR}/devel/gettext
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

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qtdoc-dir=${X11BASE}/share/doc/qt/html
CONFIGURE_ENV+=	PATH=${LOCALBASE}/gnu-autotools/bin:${PATH}
USE_REINPLACE=	yes

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
.if ${ARCH} == "amd64"
	@${REINPLACE_CMD} -e "s,-O2,${CFLAGS} -fPIC," \
		${WRKSRC}/bdb/build_unix/Makefile ${WRKSRC}/bdb/Makefile
.endif

post-install:
	@${MV} ${PREFIX}/bin/kdevelop ${PREFIX}/bin/kdevelop-bin
	@${INSTALL_SCRIPT} ${WRKDIR}/kdevelop ${PREFIX}/bin

.include <bsd.port.post.mk>

# New ports collection makefile for:	MySQL Query Browser
# Date created:				08 April 2006
# Whom:					Rainer Alves <rainer.alves@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mysql-query-browser
PORTVERSION=	1.1.18
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	MySQLAdministrationSuite

MAINTAINER=	rainer.alves@gmail.com
COMMENT=	A database querying tool for MySQL servers

LIB_DEPENDS+=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		pcre.0:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed \
		gtkdoc-mkhtml:${PORTSDIR}/textproc/gtk-doc \
		scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:19:env autoconf:259:env
CONFIGURE_ENV+=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
GTKHTML_VER=	${gtkhtml3_DETECT:R}
CONFIGURE_ARGS_GUI+=	--prefix=${X11BASE} \
			--datadir=${DATADIR} \
			--localstatedir=${PREFIX}/share/gnome
CONFIGURE_ARGS_MAIN+=	${CONFIGURE_ARGS_GUI} \
			--with-gtkhtml=${GTKHTML_VER:C/^.*\///g}
USE_ICONV=	yes
USE_GNOME=	libglade2 gnomehack gtkhtml3 intltool
USE_MYSQL=	yes
DEFAULT_MYSQL_VER=	50
BROKEN_WITH_MYSQL=	323
GNU_CONFIGURE=	yes

GUI_CONFIG_COOKIE=	${WRKDIR}/.gui_configure_done
GUI_BUILD_COOKIE=	${WRKDIR}/.gui_build_done
MAIN_CONFIG_COOKIE=	${WRKDIR}/.main_configure_done
MAIN_BUILD_COOKIE=	${WRKDIR}/.main_build_done

GUI_DIR=	${WRKSRC}/mysql-gui-common
MAIN_DIR=	${WRKSRC}/mysql-query-browser

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not build on FreeBSD < 5.x
.endif

ONLY_FOR_ARCHS=	i386

do-configure:
	@${DO_NADA}

do-build:
	@cd ${GUI_DIR}; \
	if [ ! -f ${GUI_CONFIG_COOKIE} ]; then \
		${TOUCH} ${TOUCH_FLAGS} ${GUI_CONFIG_COOKIE}; \
		${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS_GUI}; \
	fi; \
	if [ ! -f ${GUI_BUILD_COOKIE} ]; then \
		${TOUCH} ${TOUCH_FLAGS} ${GUI_BUILD_COOKIE}; \
		${GMAKE}; \
	fi
	@cd ${MAIN_DIR}; \
	if [ ! -f ${MAIN_CONFIG_COOKIE} ]; then \
		${TOUCH} ${TOUCH_FLAGS} ${MAIN_CONFIG_COOKIE}; \
		${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS_MAIN}; \
	fi; \
	if [ ! -f ${MAIN_BUILD_COOKIE} ]; then \
		${TOUCH} ${TOUCH_FLAGS} ${MAIN_BUILD_COOKIE}; \
		${GMAKE}; \
	fi

do-install:
	@cd ${GUI_DIR}; \
	${GMAKE} ${INSTALL_TARGET}
	@cd ${MAIN_DIR}; \
	${GMAKE} ${INSTALL_TARGET}

.include <bsd.port.post.mk>

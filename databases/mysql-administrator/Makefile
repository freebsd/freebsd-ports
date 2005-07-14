# New ports collection makefile for:	mysqladministrator
# Date created:				21 Febrary 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	mysql-administrator
PORTVERSION=	1.0.22a
CATEGORIES=	databases
MASTER_SITES=	http://www.softagency.co.jp/MySQL/%SUBDIR%/ \
		ftp://sunsite.dk/mirrors/mysql/%SUBDIR%/ \
		http://mysql.mediatraffic.fi/%SUBDIR%/ \
		ftp://filepile.tiscali.de/mirror/mysql/%SUBDIR%/ \
		http://mirrors.tilian.co.uk/%SUBDIR%/ \
		ftp://ftp.rtfm.no/pub/mysql/%SUBDIR%/ \
		ftp://ftp.u-paris10.fr/mysql.com/%SUBDIR%/ \
		http://mysql.oms-net.nl/%SUBDIR%/
MASTER_SITE_SUBDIR=	Downloads/MySQLAdministrationSuite

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Powerful visual administration console for MySQL environment

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
WANT_AUTOCONF_VER=	259
CONFIGURE_ENV+=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--localstatedir=${PREFIX}/share/gnome
USE_ICONV=	yes
USE_GNOME=	libglade2 gnomehack
USE_MYSQL=	yes
DEFAULT_MYSQL_VER=	41
BROKEN_WITH_MYSQL=	323 40
GNU_CONFIGURE=	yes

LIB_DEPENDS+=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2 \
		pcre.0:${PORTSDIR}/devel/pcre

BUILD_DEPENDS=  scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
RUN_DEPENDS=	${BUILD_DEPENDS}

GUI_CONFIG_COOKIE=	${WRKDIR}/.gui_configure_done
GUI_BUILD_COOKIE=	${WRKDIR}/.gui_build_done
MAIN_CONFIG_COOKIE=	${WRKDIR}/.main_configure_done
MAIN_BUILD_COOKIE=	${WRKDIR}/.main_build_done

GUI_DIR=	${WRKSRC}/mysql-gui-common
MAIN_DIR=	${WRKSRC}/mysql-administrator

.include <bsd.port.pre.mk>

# XXX
.if ${OSVERSION} < 500000
BROKEN=		Does not build on 4.x
.endif

ONLY_FOR_ARCHS=	i386

post-patch:
	@${REINPLACE_CMD} -e "s#%%PTHREAD_CFLAGS%%#${PTHREAD_CFLAGS}#" \
			${WRKSRC}/mysql-administrator/source/linux/Makefile.am
	@${CHMOD} a+x 	${WRKSRC}/mysql-gui-common/missing \
			${WRKSRC}/mysql-administrator/missing
	@${REINPLACE_CMD} -e 's#$$(datadir)/omf#$$(datadir)/gnome#' \
			${WRKSRC}/mysql-administrator/omf.make

do-configure:
	@${DO_NADA}

do-build:
	@cd ${GUI_DIR}; \
	if [ ! -f ${GUI_CONFIG_COOKIE} ]; then \
		${TOUCH} ${TOUCH_FLAGS} ${GUI_CONFIG_COOKIE}; \
		${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
	fi; \
	if [ ! -f ${GUI_BUILD_COOKIE} ]; then \
		${TOUCH} ${TOUCH_FLAGS} ${GUI_BUILD_COOKIE}; \
		${GMAKE} DATADIRNAME=share; \
	fi
	@cd ${MAIN_DIR}; \
	if [ ! -f ${MAIN_CONFIG_COOKIE} ]; then \
		${TOUCH} ${TOUCH_FLAGS} ${MAIN_CONFIG_COOKIE}; \
		${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
	fi; \
	if [ ! -f ${MAIN_BUILD_COOKIE} ]; then \
		${TOUCH} ${TOUCH_FLAGS} ${MAIN_BUILD_COOKIE}; \
		${GMAKE} DATADIRNAME=share; \
	fi

do-install:
		@cd ${GUI_DIR}; \
		${GMAKE} install
		@cd ${MAIN_DIR}; \
		${GMAKE} install

.include <bsd.port.post.mk>

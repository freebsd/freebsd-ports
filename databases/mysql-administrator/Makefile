# New ports collection makefile for:	mysqladministrator
# Date created:				21 Febrary 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	mysql-administrator
PORTVERSION=	1.1.10
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	MySQLAdministrationSuite

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Powerful visual administration console for MySQL environment

LIB_DEPENDS+=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		pcre.0:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259:env
CONFIGURE_ENV+=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--localstatedir=${PREFIX}/share/gnome
USE_ICONV=	yes
USE_GNOME=	libglade2 gnomehack
USE_MYSQL=	yes
BROKEN_WITH_MYSQL=	323
GNU_CONFIGURE=	yes

GUI_CONFIG_COOKIE=	${WRKDIR}/.gui_configure_done
GUI_BUILD_COOKIE=	${WRKDIR}/.gui_build_done
MAIN_CONFIG_COOKIE=	${WRKDIR}/.main_configure_done
MAIN_BUILD_COOKIE=	${WRKDIR}/.main_build_done

GUI_DIR=	${WRKSRC}/mysql-gui-common
MAIN_DIR=	${WRKSRC}/mysql-administrator

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		can not build on 4.x
.endif

ONLY_FOR_ARCHS=	i386

post-patch:
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
	${GMAKE} ${INSTALL_TARGET}
	@cd ${MAIN_DIR}; \
	${GMAKE} ${INSTALL_TARGET}

.include <bsd.port.post.mk>

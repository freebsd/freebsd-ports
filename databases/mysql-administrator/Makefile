# New ports collection makefile for:	mysqladministrator
# Date created:				21 Febrary 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	mysql-administrator
PORTVERSION=	1.0.1a
CATEGORIES=	databases
MASTER_SITES=	ftp://planetmirror.com/pub/mysql/%SUBDIR%/ \
		http://www.softagency.co.jp/MySQL/%SUBDIR%/ \
		ftp://sunsite.dk/mirrors/mysql/%SUBDIR%/ \
		http://mysql.mediatraffic.fi/%SUBDIR%/ \
		ftp://filepile.tiscali.de/mirror/mysql/%SUBDIR%/ \
		http://mirrors.tilian.co.uk/%SUBDIR%/ \
		ftp://ftp.rtfm.no/pub/mysql/%SUBDIR%/ \
		ftp://ftp.u-paris10.fr/mysql.com/%SUBDIR%/ \
		http://mysql.oms-net.nl/%SUBDIR%/
MASTER_SITE_SUBDIR=	Downloads/MySQLAdministrationSuite

MAINTAINER=	sem@ciam.ru
COMMENT=	Powerful visual administration console for MySQL environment

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
WANT_AUTOMAKE_VER=	14
USE_AUTOCONF=	yes
WANT_AUTOCONF_VER=	257
CONFIGURE_ENV+=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"

USE_GNOME=	libglade2
USE_MYSQL=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

LIB_DEPENDS+=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2 \
		pcre.0:${PORTSDIR}/devel/pcre

DIRS_ORDER=	mysqlxlibrary mysqladministratorlibrary \
		mysqlcommonguiparts mysqladministrator

post-patch:
	@${REINPLACE_CMD} -e "s#%%PTHREAD_CFLAGS%%#${PTHREAD_CFLAGS}#" \
			${WRKSRC}/mysqladministrator/source/linux/Makefile.am
	@${CHMOD} a+x 	${WRKSRC}/mysqlcommonguiparts/missing \
			${WRKSRC}/mysqladministrator/missing

run-autotools:
	@${DO_NADA}

do-configure:
	@${DO_NADA}

do-build:
	@for d in ${DIRS_ORDER}; do \
		${ECHO_MSG} ""; \
		${ECHO_MSG} "--->"; \
		${ECHO_MSG} "---> Building: $${d}"; \
		${ECHO_MSG} "--->"; \
		cd ${WRKSRC}/$${d}; \
		${AUTOMAKE} --foreign; ${AUTOCONF}; \
		${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
		${GMAKE}; \
	done

do-install:
	@for d in ${DIRS_ORDER}; do \
		${ECHO_MSG} ""; \
		${ECHO_MSG} "--->"; \
		${ECHO_MSG} "---> Installing: $${d}"; \
		${ECHO_MSG} "--->"; \
		cd ${WRKSRC}/$${d}; \
		${GMAKE} install; \
	done

.include <bsd.port.mk>

# New ports collection makefile for:	mysqladministrator
# Date created:				21 Febrary 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	mysql-administrator
PORTVERSION=	1.0.2b.a
PORTREVISION=	1
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
DISTNAME=	${PORTNAME}-1.0.2b-alpha

MAINTAINER=	sem@ciam.ru
COMMENT=	Powerful visual administration console for MySQL environment

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
WANT_AUTOMAKE_VER=	14
WANT_AUTOCONF_VER=	257
CONFIGURE_ENV+=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
USE_ICONV=	yes
USE_GNOME=	libglade2
USE_MYSQL=	yes
BROKEN_WITH_MYSQL=	323
GNU_CONFIGURE=	yes

LIB_DEPENDS+=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2 \
		pcre.0:${PORTSDIR}/devel/pcre

DIRS_ORDER=	mysql-gui-common mysql-administrator

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s#%%PTHREAD_CFLAGS%%#${PTHREAD_CFLAGS}#" \
			${WRKSRC}/mysql-administrator/source/linux/Makefile.am
	@${CHMOD} a+x 	${WRKSRC}/mysql-gui-common/missing \
			${WRKSRC}/mysql-administrator/missing

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
		${CP} -f ${TEMPLATES}/config.sub ./config.sub; \
		${CP} -f ${TEMPLATES}/config.guess ./config.guess; \
		${CHMOD} a+rx ./config.sub; \
		${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
		${GMAKE} DATADIRNAME=share; \
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

.include <bsd.port.post.mk>

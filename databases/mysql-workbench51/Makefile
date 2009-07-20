# New ports collection makefile for:	MySQL Workbench
# Date created:				21 June 2009
# Whom:					Maxim Ignatenko
#
# $FreeBSD$
#

PORTNAME=	mysql-workbench-oss
PORTVERSION?=	5.1.16
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	MySQLGUITools
PKGNAMESUFFIX?=	51

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	The MySQL Workbench

LIB_DEPENDS+=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		pcre.0:${PORTSDIR}/devel/pcre \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		zip:${PORTSDIR}/archivers/libzip \
		sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		cairo.2:${PORTSDIR}/graphics/cairo

MAKE_JOBS_SAFE=	yes

OPTIONS=	PYTHON	"Enable Python scripting and modules" off

USE_AUTOTOOLS=	autoheader:262 autoconf:262 automake:110 aclocal:110 libtool:15:env
AUTOMAKE_ARGS=	--add-missing --foreign
ACLOCAL_ARGS=
AUTOCONF_ARGS=
USE_LDCONFIG=	${PREFIX}/lib/mysql-workbench
SUBDIRS=	ext/yassl/taocrypt ext/yassl .
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*ext/yassl/.*(Makefile.am|configure.in)

USE_GL=		gl glu
USE_GNOME=	libglade2 intltool libgnome gtk20 pango orbit2
USE_LUA=	5.1
LUA_COMPS=	lua

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=	does not build on 6.x
.endif

.if ${PKGNAMESUFFIX} == 51
CONFLICTS=	mysql-workbench-oss52*
.endif

DATADIR=	${PREFIX}/share/mysql-workbench

CXXFLAGS+=	-I${LOCALBASE}/include -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GNOME2_DIR="${LOCALBASE}" LDFLAGS="${LDFLAGS}"  LUA_LIBS="-llua"


USE_MYSQL=	client
IGNORE_WITH_MYSQL=	323 40 41

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=	--enable-python-modules
WITH_PYTHON=	yes
.endif

run-autotools-aclocal:
.for dir in ${SUBDIRS}
	@(cd ${WRKSRC}/${dir} && \
		${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} ${ACLOCAL_ARGS})
.endfor

run-autotools-autoheader:
.for dir in ${SUBDIRS}
	@(cd ${WRKSRC}/${dir} && if ${GREP} "^AM_CONFIG_HEADER" configure.in \
		>/dev/null; then ${SETENV} ${AUTOTOOLS_ENV} ${AUTOHEADER} \
		${AUTOHEADER_ARGS}; fi)
.endfor

run-autotools-automake:
.for dir in ${SUBDIRS}
	@(cd ${WRKSRC}/${dir} && \
		${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} ${AUTOMAKE_ARGS})
.endfor

run-autotools-autoconf:
.for dir in ${SUBDIRS}
	@(cd ${WRKSRC}/${dir} && \
		${SETENV} ${AUTOTOOLS_ENV} ${AUTOCONF} ${AUTOCONF_ARGS})
.endfor

.include <bsd.port.post.mk>

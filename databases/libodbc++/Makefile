# New ports collection makefile for:	libodbc++
# Date created:		26 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libodbc++
PORTVERSION=	0.2.2
CATEGORIES=	databases devel
MASTER_SITES=	http://orcane.net/freeodbc++/download/${PORTVERSION}/

MAINTAINER=	wjv@FreeBSD.org

BROKEN=		"Does not compile"

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

# libodbc++ needs an ODBC driver manager to be installed, and it supports
# both iODBC and unixODBC.  The following variable may be set at build-time
# to either "iodbc" or "unixodbc", with the latter being the default:
DRIVER_MANAGER?=	unixodbc

.if ${DRIVER_MANAGER} == "iodbc"
LIB_DEPENDS=	iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iodbc=${LOCALBASE}
.else	# assume we're using unixODBC
LIB_DEPENDS=	odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc=${LOCALBASE}
.endif

# XXX untested
.if defined(WITH_PTHREAD)
CONFIGURE_ARGS+=	--enable-threads
.endif

# XXX needs significantly more testing
.if defined(WITH_GUI)
USE_QT_VER=	2
QT_NONSTANDARD=	yes
CONFIGURE_ARGS+=	--with-qt \
			--with-qt-includes=${X11BASE}/include/qt2 \
			--with-qt-libs=${X11BASE}/lib \
			--with-moc=${MOC} \
			--with-qtsqlxx
CONFIGURE_ENV+=	MOC="${MOC}" LIBQT="-l${QTNAME}" \
		CPPFLAGS="${QTCPPFLAGS}" LIBS="${QTCFGLIBS}"
PLIST_SUB+=	PLIST_GUI="" PLIST_NOGUI="@comment "
.else
CONFIGURE_ARGS+=	--with-isqlxx
PLIST_SUB+=	PLIST_GUI="@comment " PLIST_NOGUI=""
.endif

post-patch:
.for docdir in doc doc/progref
	@ ${REINPLACE_CMD} -e \
	  "s#\@docdir\@/\@PACKAGE\@-\@VERSION\@/#\@docdir\@/\@PACKAGE\@/#" \
	  ${WRKSRC}/${docdir}/Makefile.in
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@ cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${GMAKE} \
	  ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
	@ cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${GMAKE} \
	  ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
.endif

.include <bsd.port.mk>

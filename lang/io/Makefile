# New ports collection makefile for:	io
# Date created:		4 Nov 2005
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	io
PORTVERSION=	0.0.2010.06.07
CATEGORIES=	lang
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/ \
		${MASTER_SITE_LOCAL} \
    		http://people.freebsd.org/~gahr/distfiles/
DISTNAME=	io-${PORTVERSION:S/0.0.//}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Small prototype-based programming language

USE_ZIP=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/stevedekorte-io-f641230

# All addons that do not require extra dependencies
# Additional addons may be added as separate ports with some
# makefile hacking in a manner similar to Qt4 ports
DEFAULT_ADDONS=	AsyncRequest Blowfish Box CGI ContinuedFraction Curses \
		EditLine Flux Fnmatch LZO Loki MD5 \
		NotificationCenter Random Range Rational ReadLine SHA1 \
		SqlDatabase Syslog SystemCall Thread User Zlib

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS=	SQLITE3	"SQLite3 support"	off

.include <bsd.port.pre.mk>

.if defined(WITH_SQLITE3)
USE_SQLITE=	3
DEFAULT_ADDONS+=SQLite3
PLIST_SUB+=	SQLITE3=""
SQLITE_LIB=	${LOCALBASE}/lib/libsqlite${SQLITE_VER}.so
.else
PLIST_SUB+=	SQLITE3="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's/^add_subdirectory/#&/' \
		${WRKSRC}/addons/CMakeLists.txt
.for addon in ${DEFAULT_ADDONS}
	${ECHO} "add_subdirectory(${addon})" >> ${WRKSRC}/addons/CMakeLists.txt
.endfor
.if defined(WITH_SQLITE3)
	${REINPLACE_CMD} -e 's#.{SQLITE_LIBRARIES}#${SQLITE_LIB}#' \
		${WRKSRC}/addons/SQLite3/CMakeLists.txt
.endif

do-install:
.for bin in io io_static
	${INSTALL_PROGRAM} ${WRKSRC}/_build/binaries/${bin} ${PREFIX}/bin
.endfor
.for lib in libbasekit libgarbagecollector libcoroutine libiovmall
	${INSTALL_LIB} ${WRKSRC}/_build/dll/${lib}.so ${PREFIX}/lib
.endfor
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
.for addon in ${DEFAULT_ADDONS}
# Regex saves problems of -path not working in this macro and
# reduces the number of necessary primaries; we don't want anything
# Makefile-ish installed
	cd ${WRKSRC}/addons && \
	    ${COPYTREE_SHARE} ${addon} ${PREFIX}/lib/${PORTNAME} \
			"! -regex .*[Mm]ake[_FfL].*"
.endfor
	${MKDIR} ${PREFIX}/include/io
	${INSTALL_DATA} ${WRKSRC}/_build/headers/* ${PREFIX}/include/io

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>

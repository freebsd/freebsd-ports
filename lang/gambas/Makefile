# New ports collection makefile for:	Gambas
# Date created:				Jan 24, 2004
# Whom:					Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$

PORTNAME=		gambas
PORTVERSION=		0.92
PORTREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		http://gambas.sourceforge.net/

MAINTAINER=		thierry@pompo.net
COMMENT=		Gambas Almost Means BASic

LIB_DEPENDS=		curl.2:${PORTSDIR}/ftp/curl			\
			ltdl.4:${PORTSDIR}/devel/libltdl
RUN_DEPENDS=		pgrep:${PORTSDIR}/sysutils/pkill

USE_KDELIBS_VER=	3
USE_GETTEXT=		yes
USE_BZIP2=		yes
USE_LIBTOOL_VER=	13
LIBTOOLFILES=		configure libltdl/configure
LIBTOOLFLAGS=		# none
USE_GMAKE=		yes
USE_GCC=		3.3
CONFIGURE_ARGS=		--with-conv-includes=${LOCALBASE}/include	\
			--with-conv-libraries=${LOCALBASE}/lib
CONFIGURE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"		\
			PTHREAD_LIBS="${PTHREAD_LIBS}"
USE_MYSQL=		yes
USE_REINPLACE=		yes

LIBS2FIX=		libqt-mt libkdecore libkdeui libDCOP libkio
SRC2FIX1=		src/comp/gbi.c src/exec/gbx_library.c
SRC2FIX2=		src/comp/gbc_archive.c src/comp/gbi.c		\
			src/exec/gbx_library.c src/share/gb_component.h

.if !defined(WITHOUT_SDL)
USE_SDL=		mixer
CONFIGURE_ARGS+=	--with-sdl-includes="`${SDL_CONFIG} --cflags`"	\
			--with-sdl-libraries="`${SDL_CONFIG} --libs`"
PLIST_SUB+=		SDL=""
.else
CONFIGURE_ARGS+=	--disable-sdl
PLIST_SUB+=		SDL="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not run on FreeBSD-4.x at this time"
.endif

.for lib in ${LIBS2FIX}
NEW${lib:U}!=	${LDCONFIG} -r | ${GREP} ${lib} | ${GREP} -v 'compat/pkg'	\
		| ${AWK} -F 'lib\/' '{print $$2}'
.endfor

.if exists(${LOCALBASE}/include/postgresql/server/postgres.h)
WITH_PGSQL=		yes
.endif
.if defined(WITH_PGSQL)
LIB_DEPENDS+=		pq.3:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+=	--with-postgresql-includes=${LOCALBASE}/include/postgresql/server \
			--with-postgresql-libraries=${LOCALBASE}/lib
PLIST_SUB+=		PGSQL=""
.else
CONFIGURE_ARGS+=	--without-postgresql-includes				\
			--without-postgresql-libraries
PLIST_SUB+=		PGSQL="@comment "
.endif

.if exists(${LOCALBASE}/include/sqlite.h)
WITH_SQLITE=		yes
.endif
.if defined(WITH_SQLITE)
LIB_DEPENDS+=		sqlite.2:${PORTSDIR}/databases/sqlite
CONFIGURE_ARGS+=	--with-sqlite-includes=${LOCALBASE}/include		\
			--with-sqlite-libraries=${LOCALBASE}/lib
BUILD_DEPENDS+=		${LOCALBASE}/lib/libpub.a:${PORTSDIR}/devel/publib
PLIST_SUB+=		SQLITE=""
.else
CONFIGURE_ARGS+=	--without-sqlite-includes				\
			--without-sqlite-libraries
PLIST_SUB+=		SQLITE="@comment "
.endif

post-extract:
	@${CHMOD} go+x ${WRKSRC}/examples/WebBrowser

post-patch:
.for src in ${SRC2FIX1}
	@${REINPLACE_CMD} -e "s|libqt-mt.so.3|${NEWLIBQT-MT}|g"			\
			-e "s|libkdecore.so.4|${NEWLIBKDECORE}|g"		\
			-e "s|libkdeui.so.4|${NEWLIBKDEUI}|g"			\
			-e "s|libDCOP.so.4|${NEWLIBDCOP}|g"			\
			-e "s|libkio.so.4|${NEWLIBKIO}|g" ${WRKSRC}/${src}
.endfor
.for src in ${SRC2FIX2}
	@${REINPLACE_CMD} -e "s|/usr/bin/gb|${PREFIX}/bin/gb|g"	\
		${WRKSRC}/${src}
.endfor
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|# FreeBSD-Doc-Comment||" ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/Makefile.in
	@${RM} ${WRKSRC}/examples/Database/DataReportExample/Fconn.class.orig	\
		${WRKSRC}/examples/Database/DataReportExample/Fmain.class.orig

.include <bsd.port.post.mk>

# New ports collection makefile for:	Gambas
# Date created:				Jan 24, 2004
# Whom:					Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$

PORTNAME=		gambas
PORTVERSION=		1.0.19
PORTREVISION=	10
CATEGORIES=		lang
MASTER_SITES=		SF

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Gambas Almost Means BASic

LIB_DEPENDS=		curl.6:${PORTSDIR}/ftp/curl	\
			ml.0:${PORTSDIR}/math/ldouble

USE_AUTOTOOLS=		libltdl:22 libtool:22
USE_KDELIBS_VER=	3
USE_GETTEXT=		yes
USE_BZIP2=		yes
USE_GMAKE=		yes
CONFIGURE_ARGS=		--with-conv-includes=${LOCALBASE}/include	\
			--with-conv-libraries=${LOCALBASE}/lib		\
			--with-intl-includes=${LOCALBASE}/include	\
			--with-intl-libraries=${LOCALBASE}/lib		\
			--with-conv-includes=${LOCALBASE}/include	\
			--with-conv-libraries=${LOCALBASE}/lib		\
			--with-gettext-includes=${LOCALBASE}/include	\
			--with-gettext-libraries=${LOCALBASE}/lib	\
			--with-moc=${LOCALBASE}/bin
CONFIGURE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"		\
			PTHREAD_LIBS="${PTHREAD_LIBS}"

LIBS2FIX=		libqt-mt libkdecore libkdeui libDCOP libkio
SRC2FIX1=		configure src/comp/gbi.c src/exec/gbx_library.c
SRC2FIX2=		src/comp/gbc_archive.c src/comp/gbi.c		\
			src/exec/gbx_library.c src/share/gb_component.h
SRC2FIX3=		Makefile.in src/exec/gbx_project.c

DIR2PRUNE1=		help/hello-world
DIR2PRUNE2=		Miscellaneous/Notepad/.lang Drawing/ImageViewer/.lang	\
			Miscellaneous/Evaluator/.lang Exec/MoviePlayer/.lang	\
			Miscellaneous/Explorer/.lang Database/Database/.lang	\
			Drawing/OnScreenDisplay/.lang Basic/Timer/.lang		\
			Basic/Object/.lang Basic/Collection/.lang		\
			Automation/Scripting/.lang Automation/KateBrowser/.lang

.if defined(WITHOUT_MYSQL)
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=		MYSQL="@comment "
.else
CONFIGURE_ARGS+=	--with-mysql-includes=${LOCALBASE}/include/mysql	\
			--with-mysql-libraries=${LOCALBASE}/lib/mysql
USE_MYSQL=		yes
PLIST_SUB+=		MYSQL=""
.endif

.if !defined(WITHOUT_SDL)
USE_SDL=		mixer
CONFIGURE_ARGS+=	--with-sdl-includes="`${SDL_CONFIG} --cflags`"	\
			--with-sdl-libraries="`${SDL_CONFIG} --libs`"
PLIST_SUB+=		SDL=""
.else
CONFIGURE_ARGS+=	--disable-sdl
PLIST_SUB+=		SDL="@comment "
.endif

.if !defined(WITHOUT_XML)
USE_GNOME=		libxml2 libxslt
PLIST_SUB+=		XML=""
CONFIGURE_ARGS+=	--with-libxml-includes=${LOCALBASE}/include/libxml2	\
			--with-libxml-libraries=${LOCALBASE}/lib		\
			--with-xslt-includes=${LOCALBASE}/include/libxml2	\
			--with-xslt-libraries=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-libxml --disable-xslt
PLIST_SUB+=		XML="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "ia64"
BROKEN=			Segfault during build on ${ARCH}
.endif

.for lib in ${LIBS2FIX}
NEW${lib:U}!=	${LDCONFIG} -r | ${GREP} ${lib} | ${GREP} -v 'compat/pkg'	\
		| ${AWK} -F 'lib\/' '{print $$2}'
.endfor

.if exists(${LOCALBASE}/bin/pg_config)
WITH_PGSQL=		yes
.endif
.if defined(WITH_PGSQL)
USE_PGSQL=		yes
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
LIB_DEPENDS+=		sqlite.2:${PORTSDIR}/databases/sqlite2
CONFIGURE_ARGS+=	--with-sqlite-includes=${LOCALBASE}/include		\
			--with-sqlite-libraries=${LOCALBASE}/lib
BUILD_DEPENDS+=		${LOCALBASE}/lib/libpub.a:${PORTSDIR}/devel/publib
PLIST_SUB+=		SQLITE=""
.else
CONFIGURE_ARGS+=	--disable-sqlite
PLIST_SUB+=		SQLITE="@comment "
.endif

.if exists(${LOCALBASE}/bin/rpmbuild)
WITH_RPMBUILD=		yes
.endif
.if defined(WITH_RPMBUILD)
RUN_DEPENDS+=		rpmbuild:${PORTSDIR}/archivers/rpm4
.endif

pre-configure:
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
.for src in ${SRC2FIX3}
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g"	${WRKSRC}/${src}
.endfor
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|# FreeBSD-Doc-Comment||" ${WRKSRC}/Makefile.in
.endif

post-install:
	@${RMDIR} ${DIR2PRUNE1:S|^|${DATADIR}/|}
.if !defined(NOPORTDOCS)
	@${RMDIR} ${DIR2PRUNE2:S|^|${EXAMPLESDIR}/|}
.endif

.include <bsd.port.post.mk>

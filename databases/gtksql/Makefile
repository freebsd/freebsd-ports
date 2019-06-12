# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	gtksql
PORTVERSION=	0.4.5
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-testing/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical query tool for PostgreSQL/MySQL/SQLite

DEPRECATED=	Abandonware using sys/dir.h
EXPIRATION_DATE=	2019-07-12

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libscintilla.so:x11-toolkits/scintilla
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		gettext gmake localbase pkgconfig
USE_GNOME=	gdkpixbuf2 gtk20 cairo
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

OPTIONS_DEFINE=	AVAHI DOCS
OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	postgresql

AVAHI_LIB_DEPENDS=	libavahi-common.so:net/avahi-app
AVAHI_CONFIGURE_OFF=	--without-avahi

MYSQL_USES=		mysql
MYSQL_CPPFLAGS=		-I${LOCALBASE}/include/mysql
MYSQL_LDFLAGS=		-L${LOCALBASE}/lib/mysql
MYSQL_CONFIGURE_OFF=	--without-mysql

SQLITE_USES=		sqlite
SQLITE_CONFIGURE_OFF=	--without-sqlite

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lstdc++|| ; \
		 /^PACKAGE_LIBS=/s|$${packagesrcdir}.*scintilla.a|-lscintilla -lscintilla_lexers| ; \
		 /^CPPFLAGS=/s|../scintilla/include|${LOCALBASE}/include/scintilla| ; \
		 /ac_header/s|postgres.h|libpq-fe.h| ; \
		 s|/usr/local|${PREFIX}| ; \
		 s|-R|-Wl,-rpath=| ; \
		 /^packagedatadir/s|=.*|=share/gtksql|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|-O1|| ; \
		 s|-g$$|-DGTK|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|<postgres\.h>|<postgresql/internal/c.h>|' \
		${WRKSRC}/src/d_postgres_f.c
	@${REINPLACE_CMD} -e \
		's|mozilla|xdg-open|' \
		${WRKSRC}/src/gtkui-object.c
	@${REINPLACE_CMD} -e \
		's|/usr/local/gtksql|${PREFIX}/lib/gtksql|' \
		${WRKSRC}/src/plugins.c
# Some structure names were renamed in Scintilla.h (v3.7.1)
	@${REINPLACE_CMD} -E \
		's|^#include <string.h>$$|#include <stdlib.h>\${.newline}&| ; \
		 s|(CharacterRange\|TextRange)|Sci_&|' \
		${WRKSRC}/src/gtksql_query_scintilla.c

.include <bsd.port.mk>

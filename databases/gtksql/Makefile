# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	gtksql
PORTVERSION=	0.4.5
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-testing/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical query tool for PostgreSQL/MySQL/SQLite

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libscintilla.so:x11-toolkits/scintilla
RUN_DEPENDS=	xdg-open:devel/xdg-utils

BROKEN=		does not build (incomplete definition of type 'struct CharacterRange')

USES=		gettext gmake pkgconfig
USE_GNOME=	gtk20 cairo glib20 pango
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

CPPFLAGS+=	-I${LOCALBASE}/include/scintilla -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lscintilla -lscintilla_lexers
LDFLAGS+=	-lgtk-x11-2.0 -lgdk-x11-2.0 -lpangocairo-1.0 -latk-1.0 -lcairo

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
		'/-lstdc++/s|^|#| ; \
		 /scintilla.a/s|^|#| ; \
		 /\/scintilla\/include/s|^|#| ; \
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

.include <bsd.port.mk>

# New ports collection makefile for:	gambas2
# Date created:		2009-01-16
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gambas2
PORTVERSION=	2.15.2
CATEGORIES=	lang
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A basic language with object extensions (meta port)

RUN_DEPENDS=	gbi2:${PORTSDIR}/lang/gambas2-base \
		${GAMBASCOMPDIR}/gb.settings.component:${PORTSDIR}/lang/gambas2-components

NO_MTREE=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

OPTIONS=	IDE	"IDE for the gambas programming language"	on \
		COMPRESS_BZLIB2	"The gambas bzlib2 compression component"	on \
		COMPRESS_ZLIB	"The gambas zlib compression component"	on \
		CORBA	"The gambas corba component"	on \
		CRYPT	"The gambas crypt encription component"	on \
		DB_FIREBIRD	"The Firebird driver component"	on \
		DB_ODBC	"The odbc driver component"	on \
		DB_MYSQL	"The MySQL driver component"	on \
		DB_PGSQL	"The postgresql driver component"	on \
		DB_SQLITE2	"The SQlite2 driver component"	on \
		DB_SQLITE3	"The SQlite3 driver component"	on \
		DESKTOP	"Portland project compatibility component"	on \
		GTK	"The Gtk2 GUI component"	on \
		GTK_SVG	"The SVG importing component"	on \
		IMAGE	"The image effects component"	on \
		NET	"The gambas networking component"	on \
		NET_CURL	"The advanced networking component"	on \
		NET_SMTP	"The gambas component to use smtp protocol"	on \
		OPENGL	"The OpenGL component for gambas"	on \
		PCRE	"The gambas regexp component"	on \
		PDF	"The gambas pdf component"	on \
		QT	"The gambas Qt GUI component"	on \
		QT_KDE	"The gambas KDE component"	on \
		SDL	"The gambas SDL component"	on \
		SDL_SOUND	"The gambas SDL sound component"	on \
		XML	"The gambas XML component"	on

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PORTNAME}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif
		
.include <bsd.port.pre.mk>

GAMBASCOMPDIR=	${LOCALBASE}/lib/${PORTNAME}
ALL_OPTIONS=	IDE COMPRESS_BZLIB2 COMPRESS_ZLIB CORBA CRYPT DB_FIREBIRD DB_ODBC \
		DB_MYSQL DB_PGSQL DB_SQLITE2 DB_SQLITE3 DESKTOP GTK GTK_SVG \
		IMAGE NET NET_CURL NET_SMTP OPENGL PCRE PDF QT QT_KDE SDL \
		SDL_SOUND XML

IDE_COMP=	editors/gambas2-ide
COMPRESS_BZLIB2_COMP=	archivers/gambas2-gb-compress-bzlib2
COMPRESS_ZLIB_COMP=	archivers/gambas2-gb-compress-zlib
CORBA_COMP=	devel/gambas2-gb-corba
CRYPT_COMP=	security/gambas2-gb-crypt
DB_FIREBIRD_COMP=	databases/gambas2-gb-db-firebird
DB_ODBC_COMP=	databases/gambas2-gb-db-odbc
DB_MYSQL_COMP=	databases/gambas2-gb-db-mysql
DB_PGSQL_COMP=	databases/gambas2-gb-db-postgresql
DB_SQLITE2_COMP=	databases/gambas2-gb-db-sqlite2
DB_SQLITE3_COMP=	databases/gambas2-gb-db-sqlite3
DESKTOP_COMP=	x11/gambas2-gb-desktop
GTK_COMP=	x11-toolkits/gambas2-gb-gtk
GTK_SVG_COMP=	graphics/gambas2-gb-gtk-svg
IMAGE_COMP=	graphics/gambas2-gb-image
NET_COMP=	net/gambas2-gb-net
NET_CURL_COMP=	ftp/gambas2-gb-net-curl
NET_SMTP_COMP=	mail/gambas2-gb-net-smtp
OPENGL_COMP=	graphics/gambas2-gb-opengl
PCRE_COMP=	devel/gambas2-gb-pcre
PDF_COMP=	graphics/gambas2-gb-pdf
QT_COMP=	x11-toolkits/gambas2-gb-qt
QT_KDE_COMP=	x11/gambas2-gb-qt-kde
SDL_COMP=	devel/gambas2-gb-sdl
SDL_SOUND_COMP=	audio/gambas2-gb-sdl-sound
XML_COMP=	textproc/gambas2-gb-xml

.for OPT in ${ALL_OPTIONS}
.	if defined(WITH_${OPT})  && !defined(WITHOUT_${OPT})
OPT_TMP=	${OPT:L}
.		if ${OPT_TMP} == "ide"
RUN_DEPENDS+=	${LOCALBASE}/bin/gambas2:${PORTSDIR}/${${OPT}_COMP}
.	else
RUN_DEPENDS+=	${GAMBASCOMPDIR}/gb.${OPT:S/_/./:S/PGSQL/POSTGRESQL/:L}.so:${PORTSDIR}/${${OPT}_COMP}
.		endif
.	endif
.endfor

do-install: build
	@${DO_NADA}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

# New ports collection makefile for:   scriba
# Date created:        07 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	scriba
PORTVERSION=	20b0
CATEGORIES=	lang
MASTER_SITES=	http://www.scriptbasic.com/download/
DISTNAME=	${PORTNAME}-v2.0b0-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scripting implementation of the BASIC language

USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes
USE_PERL5=	yes
CFLAGS+=	-fPIC
PORTDOCS=	*

# Extensions that depend on external libs default to off

OPTIONS=	BDB	"Berkeley DB extension"		off \
		CURL	"CURL extension"		off \
		GD	"gd extension"			off \
		MYSQL	"MySQL extension (3.2.3 only)"	off \
		ODBC	"ODBC extension"		off \
		PGSQL	"PostgreSQL extension"		off \
		XML	"libxml2 extension"		off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		coredumps a lot
.endif

.if ${ARCH} == "amd64"
IGNORE=		need base libraries built with -fPIC
.endif

.if ${ARCH} == "ia64"
BROKEN=		fails to compile
.endif

# Dependencies for port options

.if defined(WITH_BDB)
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
PLIST_SUB+=	BDB=""
.else
PLIST_SUB+=	BDB="@comment "
.endif

.if defined(WITH_CURL)
LIB_DEPENDS+=	curl.3:${PORTSDIR}/ftp/curl
PLIST_SUB+=	CURL=""
.else
PLIST_SUB+=	CURL="@comment "
.endif

.if defined(WITH_GD)
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
PLIST_SUB+=	GD=""
.else
PLIST_SUB+=	GD="@comment "
.endif

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_ODBC)
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
PLIST_SUB+=	ODBC=""
.else
PLIST_SUB+=	ODBC="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_XML)
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
PLIST_SUB+=	XML=""
.else
PLIST_SUB+=	XML="@comment "
.endif

post-patch:
	# Put esd.pm in a directory where perl will find it
	cd ${WRKSRC} && ${MKDIR} jamal && ${CP} esd.pm jamal
	${GREP} -Rl '^#!.*bin/perl' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e 's,^#!.*bin/perl,#!${PERL},'
	${REINPLACE_CMD} \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		-e 's,%%X11BASE%%,${X11BASE},g' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%DATADIR%%,${DATADIR},g' \
		-e 's,%%CC%%,${CC},g' \
		-e 's,%%CFLAGS%%,${CFLAGS},g' \
		-e 's,%%LDFLAGS%%,${LDFLAGS},g' \
		-e 's,%%PTHREAD_LIBS%%,${PTHREAD_LIBS},g' \
		-e 's,root:root,root:wheel,g' \
		${WRKSRC}/setup.pl ${WRKSRC}/scriba.c ${WRKSRC}/make_gcc.jim

# Remove extensions not selected as options

.if !defined(WITH_BDB)
	@${RM} -rf ${WRKSRC}/extensions/bdb
.endif

.if !defined(WITH_CURL)
	@${RM} -rf ${WRKSRC}/extensions/curl
.endif

.if !defined(WITH_GD)
	@${RM} -rf ${WRKSRC}/extensions/gd
.endif

.if !defined(WITH_MYSQL)
	@${RM} -rf ${WRKSRC}/extensions/mysql
.endif

.if !defined(WITH_ODBC)
	@${RM} -rf ${WRKSRC}/extensions/odbc
.endif

.if !defined(WITH_PGSQL)
	@${RM} -rf ${WRKSRC}/extensions/psql
.endif

.if !defined(WITH_XML)
	@${RM} -rf ${WRKSRC}/extensions/xml
.endif

do-build:
# -I allows script to include the Jamal preprocessor
	cd ${WRKSRC} && export PERL5OPT='-I${WRKSRC}' && \
	${PERL} setup.pl --unix

do-install:
	cd ${WRKSRC} && \
	${PERL} setup.pl --unix --no-install-interactive --install && \
	${SH} install.sh

.include <bsd.port.post.mk>

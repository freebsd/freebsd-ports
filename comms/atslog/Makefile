# New ports collection makefile for:    atslog
# Date created:                         27 November 2006
# Whom:                                 Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	atslog
PORTVERSION=	2.1.1
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	BERLIOS

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Software for collecting and analyzing calls from different PBX models

OPTIONS=	LIBWRAP		"Enable TCP wrapper support"			on \
		MYSQL		"Enable MySQL support"				on \
		PGSQL		"Enable PostgreSQL support"			off \
		WWW		"Install web interface"				on \
		WWWGD		"Graphic reports"				on

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_RC_SUBR=	${PORTNAME}d
PORTDOCS=	CHANGES ChangeLog DEINSTALL INSTALL LICENSE TODO UPDATING USAGE
SUB_FILES=	pkg-message
MANLANG=	"" ru.KOI8-R
MAN8=		${USE_RC_SUBR}.8 ${PORTNAME}master.8
CONFIGS=	${PORTNAME}.conf.default ${PORTNAME}.conf.default.rus
CONFIGURE_ARGS+=--localstatedir=/var

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MYSQL) && !defined(WITH_PGSQL)
IGNORE=	is useless without a database. Please (re)run 'make config' and choose one of PGSQL and MYSQL"
.endif

.if !defined(WITHOUT_WWW)
USE_PHP=	pcre
WANT_PHP_WEB=	yes
PLIST_SUB+=	WWW=""
.if !defined(WITHOUT_WWWGD)
USE_PHP+=	gd
.endif
.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif
.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif
.else
PLIST_SUB+=	WWW="@comment "
.endif

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if defined(WITHOUT_LIBWRAP)
CONFIGURE_ARGS+=--disable-libwrap
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|createsqltables.|${DATADIR}/sql/createsqltables.|g' \
	    -e 's|data.sql|${DATADIR}/sql/data.sql|' ${WRKSRC}/data/sql/install-sql.pl

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${USE_RC_SUBR}/${USE_RC_SUBR} ${PREFIX}/bin
	@${MKDIR} ${MANPREFIX}/man/man8
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/man/en/${i} ${MANPREFIX}/man/man8
.endfor
.for lang in ${MANLANG:N""}
	@${MKDIR} ${MANPREFIX}/man/${lang}/man8
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/man/${lang}/${i} ${MANPREFIX}/man/${lang}/man8
.endfor
.endfor
.if !exists(${PREFIX}/etc/${PORTNAME}.conf)
	${INSTALL_DATA} ${WRKSRC}/include/${PORTNAME}.conf.default ${PREFIX}/etc/${PORTNAME}.conf
.endif
.for i in ${CONFIGS}
	${INSTALL_DATA} ${WRKSRC}/include/${i} ${PREFIX}/etc/
.endfor
.for i in atslogcleardb.pl atslogdb.pl atslogmaster
	${INSTALL_SCRIPT} ${WRKSRC}/include/${i} ${PREFIX}/bin
.endfor
	${MKDIR} ${DATADIR}/lang
	cd ${WRKSRC}/include && \
	${FIND} lang -type f ! -iregex ".*Makefile" -exec \
		${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
	${MKDIR} ${EXAMPLESDIR}/textlogs
	cd ${WRKSRC}/data && \
	${FIND} textlogs -type f -exec \
		${INSTALL_DATA} "{}" "${EXAMPLESDIR}/{}" \;
	${MKDIR} ${DATADIR}/sql
	cd ${WRKSRC}/data && \
	${FIND} sql -type f -iregex ".*\.sql" -exec \
		${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
	${INSTALL_SCRIPT} ${WRKSRC}/data/sql/install-sql.pl ${DATADIR}/sql
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	cd ${WRKSRC}/libexec && \
	${FIND} -E . -type f ! -iregex ".*\.(sh|orig)" -exec \
		${INSTALL_DATA} "{}" "${PREFIX}/libexec/${PORTNAME}/{}" \;
	${INSTALL_SCRIPT} ${WRKSRC}/libexec/genindex.sh ${PREFIX}/libexec/${PORTNAME}/
.if !defined(WITHOUT_WWW)
	${MKDIR} ${PREFIX}/www/${PORTNAME}
	cd ${WRKSRC}/www && \
	${FIND} . -type d ! -empty -exec \
		${MKDIR} "${PREFIX}/www/${PORTNAME}/{}" \; && \
	${FIND} -E . -type f ! -iregex "(.*Makefile|.*\.orig)" -exec \
		${INSTALL_DATA} "{}" "${PREFIX}/www/${PORTNAME}/{}" \;
.if !exists(${PREFIX}/www/${PORTNAME}/include/config.inc.php)
	${INSTALL_DATA} ${WRKSRC}/www/include/config.inc.php.default \
		${PREFIX}/www/${PORTNAME}/include/config.inc.php
.endif
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/${PORTNAME}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

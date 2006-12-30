# New ports collection makefile for:    atslog
# Date created:                         27 November 2006
# Whom:                                 Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	atslog
PORTVERSION=	2.0.0.p4
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=${PORTNAME}
DISTNAME=	${PORTNAME}-2.0.0pre4

MAINTAINER=	ports@logvinov.com
COMMENT=	Software for collecting and analyzing calls from different PBX models

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql

OPTIONS=	LIBWRAP		"Enable TCP wrapper support"			on \
		WWW		"Install web interface"				on \
		WWWGD		"Graphic reports"				on

HAS_CONFIGURE=	yes
USE_PERL5=	yes
USE_MYSQL=	yes
USE_RC_SUBR=	${PORTNAME}d
PORTDOCS=	CHANGES ChangeLog DEINSTALL INSTALL LICENSE TODO UPDATING USAGE
SUB_FILES=	pkg-message
MANLANG=	"" ru.KOI8-R
MAN8=		${USE_RC_SUBR}.8 ${PORTNAME}master.8
CONFIGS=	${PORTNAME}.conf.default ${PORTNAME}.conf.default.rus
CONFIGURE_ARGS+=--prefix=${PREFIX} --localstatedir=/var

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_WWW)
USE_PHP=	mysql pcre
WANT_PHP_WEB=	yes
PLIST_SUB+=	WWW=""
.if !defined(WITHOUT_WWWGD)
USE_PHP+=	gd
.endif
.include "${PORTSDIR}/Mk/bsd.php.mk"
.else
PLIST_SUB+=	WWW="@comment "
.endif

post-patch:
.if defined(WITHOUT_LIBWRAP)
	@${REINPLACE_CMD} -e 's|LIBWRAP=|#LIBWRAP=|' ${WRKSRC}/${USE_RC_SUBR}/Makefile
	@${REINPLACE_CMD} -e 's|#define|//#define|' ${WRKSRC}/${USE_RC_SUBR}/${USE_RC_SUBR}.h
.endif
	@${REINPLACE_CMD} -e 's|createsqltables.mysql.sql|${DATADIR}/sql/createsqltables.mysql.sql|' \
	    -e 's|data.sql|${DATADIR}/sql/data.sql|' ${WRKSRC}/data/sql/install-sql.pl
.for i in ${CONFIGS}
	@${REINPLACE_CMD} -e 's|/log|/log/atslog|' ${WRKSRC}/include/${i}.in
.endfor
	@${MV} ${WRKSRC}/www/include/set/conf.inc.php ${WRKSRC}/www/include/set/conf.inc.default.php

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
.for i in atslogcleardb.pl atslogdaily atslogdb.pl atslogmaster atslogrotate
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
	${FIND} * -type f -exec \
		${INSTALL_DATA} "{}" "${PREFIX}/libexec/${PORTNAME}/{}" \;
.if !defined(WITHOUT_WWW)
	${MKDIR} ${PREFIX}/www/${PORTNAME}
	cd ${WRKSRC}/www && \
	${FIND} * -type d ! -empty -exec \
		${MKDIR} "${PREFIX}/www/${PORTNAME}/{}" \; && \
	${FIND} -E * -type f ! -iregex ".*Makefile" -exec \
		${INSTALL_DATA} "{}" "${PREFIX}/www/${PORTNAME}/{}" \;
.if !exists(${PREFIX}/www/${PORTNAME}/include/set/conf.inc.php)
	${INSTALL_DATA} ${WRKSRC}/www/include/set/conf.inc.default.php \
		${PREFIX}/www/${PORTNAME}/include/set/conf.inc.php
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

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.include <bsd.port.post.mk>

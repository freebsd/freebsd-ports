# New ports collection makefile for:	fossology
# Date created:				2008-06-21
# Whom:					alepulver
#
# $FreeBSD$
#

# NOTES:
# - Possible deps alternatives (don't know if they work):
#   graphics/xpdf -> graphics/poppler-utils
#   archivers/rpm4 -> archivers/rpm2cpio
#
# TODO:
# - Add status command to rc.d script (run through "daemon -p ...")
# - Add crontab entry for postgres db optimizations?
#

PORTNAME=	fossology
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	License analysis tool for Open Source software

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		${SITE_PERL}/Text/Template.pm:${PORTSDIR}/textproc/p5-Text-Template \
		svn:${PORTSDIR}/devel/subversion
LIB_DEPENDS=	extractor.2:${PORTSDIR}/textproc/libextractor
RUN_DEPENDS=	cabextract:${PORTSDIR}/archivers/cabextract \
		icat:${PORTSDIR}/sysutils/sleuthkit \
		pdftotext:${PORTSDIR}/graphics/xpdf \
		rpm2cpio:${PORTSDIR}/archivers/rpm4 \
		upx:${PORTSDIR}/archivers/upx \
		unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip \
		bash:${PORTSDIR}/shells/bash \
		wget:${PORTSDIR}/ftp/wget

USE_APACHE=	2.0+
USE_CDRTOOLS=	yes
USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_PERL5=	yes
USE_PGSQL=	yes
IGNORE_WITH_PGSQL=	73 74 80
USE_PHP=	pgsql session posix pcre
IGNORE_WITH_PHP=4
WANT_PHP_CLI=	yes
WANT_PHP_WEB=	yes
USE_RC_SUBR=	fossology
REINPLACE_ARGS=	-i ''

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

SUB_FILES=	pkg-message
SUB_LIST=	FOSS_DB="${FOSS_DB}"
PLIST_SUB=	FOSS_DB="${FOSS_DB:S/${PREFIX}\///}"

MAN1=		cp2foss.1 fo_notify.1 fossjobs.1 fosslic.1

FOSS_DB?=	${DATADIR}/repository
LIBDIR=		${PREFIX}/lib	# is /usr/lib by default, and affects build

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
IGNORE=		needs at least FreeBSD 7.x, because it uses librt
.endif

post-patch:
# Fix paths (respect PREFIX, etc)
	@${GREP} -Rl /bin/bash ${WRKSRC} | ${GREP} -v UnMagic.mime | \
	    ${XARGS} ${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|'
	@${GREP} -Rl /usr/bin/php ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/bin/php|${LOCALBASE}/bin/php|'
	@${REINPLACE_CMD} -Ee 's|^(PREFIX=).*|\1${PREFIX}|; \
		s|^(LIBDIR=).*|\1${LIBDIR}|; \
		s|^(REPODIR=).*|\1${FOSS_DB}|; \
		s|^(MANDIR=).*|\1${MANPREFIX}/man|; \
		s|^(CC=).*|\1${CC}|; \
		s|^(CFLAGS=)(.*)|\1${CFLAGS} \2|; \
		s|^(CFLAGS_DB=)(.*)|\1${CFLAGS} \2|; \
		s|^(CFLAGS_REPO=)(.*)|\1${CFLAGS} \2|; \
		s|^(INSTALL =).*|\1 ${INSTALL}|;' \
		${WRKSRC}/Makefile.conf
# Fix build flags and source
	@${GREP} -ERl '(stat|fopen|mmap|lseek|off)64' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -Ee 's,(stat|fopen|mmap|lseek|off)64,\1,g'
# Fix PostgreSQL user name (postgres -> pgsql)
	@${REINPLACE_CMD} -e 's|su postgres|su pgsql|' \
		${WRKSRC}/db/dbcreate.in
# Fix hostname invocation
	@${REINPLACE_CMD} -Ee 's|(hostname) --fqdn|\1|' \
		${WRKSRC}/cli/fo_notify.php
# Add path to repository (might be hardcoded in other parts of FOSSology)
	@${ECHO_CMD} "${FOSS_DB}" > ${WRKSRC}/common/defconf/RepPath.conf
# Do not install init.d script (we use our own)
	@${REINPLACE_CMD} -Ee 's|^(install: all) install-init|\1|' \
		${WRKSRC}/scheduler/Makefile

pre-install:
	@${MKDIR} ${PREFIX}/lib/fossology/agents ${DATADIR}/php

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/INSTALL* ${DOCSDIR}
.endif
# Copy .sample (defaults) to .conf when not present
.for f in Db Depth Hosts Proxy RepPath
	@cd ${PREFIX}/etc/fossology && test -f ${f}.conf || \
		${CP} ${f}.conf.sample ${f}.conf
.endfor
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>

# New ports collection makefile for:	php3
# Date created:		7 Sep 2000
# Whom:			Peter Pentchev <roam@orbitel.bg>
#
# $FreeBSD$
#

PORTNAME=	php
PORTVERSION=	3.0.18
PORTREVISION=	1
CATEGORIES=	lang www
MASTER_SITES=	ftp://ftp.php.net/pub/${PHP_DISTDIR}/ \
		http://us.php.net/${PHP_DISTDIR}/ \
		http://php.he.net/${PHP_DISTDIR}/ \
		http://www.php3.de/${PHP_DISTDIR}/ \
		http://au.php.net:81/${PHP_DISTDIR}/ \
		http://at.php.net/${PHP_DISTDIR}/ \
		http://br.php.net/${PHP_DISTDIR}/ \
		http://php.easydns.com/${PHP_DISTDIR}/ \
		http://www.php.cz/${PHP_DISTDIR}/ \
		http://php3.globe.de/${PHP_DISTDIR}/

MAINTAINER=	roam@FreeBSD.org

FORBIDDEN=	"Use lang/php3 instead"

PHP_DISTDIR=	distributions

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-apache \
		--with-system-regex \
		--with-config-file-path=${PREFIX}/etc \
		--disable-debug \
		--enable-track-vars \
		--without-gd

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}"

PHPDOCDIR=	${PREFIX}/share/doc/php
PLIST_SUB=	PHPDOCDIR=${PHPDOCDIR:S/^${PREFIX}\///}

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.php

post-install:
	@${INSTALL_DATA} ${WRKSRC}/php3.ini-dist ${PREFIX}/etc

.if	!defined(NOPORTDOCS)
	@${MKDIR} ${PHPDOCDIR}/html
.for i in CODING_STANDARDS LICENSE
	@${INSTALL_DATA} ${WRKSRC}/$i ${PHPDOCDIR}
.endfor
	@for i in ${WRKSRC}/doc/*; do				\
		${INSTALL_DATA} $$i ${PHPDOCDIR}/html/ ;	\
	done
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.mk>

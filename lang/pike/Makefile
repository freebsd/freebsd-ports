# New ports collection makefile for:	pike
# Version required:	0.6
# Date created:		16 Jan 1999
# Whom:			vns@delta.odessa.ua
#
# $FreeBSD$
#

DISTNAME=	Pike-v0.6.110
PKGNAME=	pike-0.6
CATEGORIES=	lang
MASTER_SITES=	http://pike.idonex.se/download/

MAINTAINER=	vns@delta.odessa.ua

pre-fetch:
.if !defined(BATCH)
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.pike
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/src/

IS_INTERACTIVE=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS?= \
	--without-ttflib \
	--without-gdbm \
	--without-mysql \
	--without-postgresql \
	--without-msql \
	--without-jpeg

pre-configure:
	@${ECHO} ${CONFIGURE_ARGS}

.include <bsd.port.mk>

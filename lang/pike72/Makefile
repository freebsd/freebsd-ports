# New ports collection makefile for:	pike
# Date created:		16 Jan 1999
# Whom:			vns@delta.odessa.ua
#
# $FreeBSD$
#

PORTNAME=	pike
PORTVERSION=	0.6
CATEGORIES=	lang
MASTER_SITES=	http://pike.idonex.se/download/
DISTNAME=	Pike-v0.6.110

MAINTAINER=	vns@delta.odessa.ua

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

pre-fetch:
.if !defined(BATCH)
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.pike
.endif

pre-configure:
	@${ECHO} ${CONFIGURE_ARGS}

pre-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif
.include <bsd.port.mk>

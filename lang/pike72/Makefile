# New ports collection makefile for:	pike
# Date created:		16 Jan 1999
# Whom:			vns@delta.odessa.ua
#
# $FreeBSD$
#

PORTNAME=	pike
PORTVERSION=	7.0.78
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.roxen.com/pub/pike/all/${PORTVERSION}/
DISTNAME=	Pike-v${PORTVERSION}

MAINTAINER=	vns@delta.odessa.ua

WRKSRC=		${WRKDIR}/${DISTNAME}/src/

IS_INTERACTIVE=	yes
GNU_CONFIGURE=  yes
.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.else
CONFIGURE_ARGS?= \
	--without-ttflib \
	--without-gdbm \
	--without-mysql \
	--without-postgresql \
	--without-msql \
	--without-jpeg
.endif
CONFIGURE_ARGS+= --with-poll

pre-fetch:
.if !defined(BATCH)
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.pike
.endif

pre-configure:
	@${ECHO} ${CONFIGURE_ARGS}

pre-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}pike ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}hilfe ${PREFIX}/bin
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/include/pike/*.h
	${CHMOD} ${SHAREMODE} ${PREFIX}/include/pike/*.h

.include <bsd.port.mk>

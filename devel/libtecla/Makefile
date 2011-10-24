# ex:ts=8
# New ports collection makefile for:	libtecla
# Date created:		Feb 12, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libtecla
PORTVERSION=	1.6.1
CATEGORIES=	devel
MASTER_SITES=	http://www.astro.caltech.edu/~mcs/tecla/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive command line editing facilities

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
USE_SUBMAKE=	yes
ALL_TARGET=	default
USE_LDCONFIG=	yes
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		REALCURDIR="${.CURDIR}" \
		PORTNAME="${PORTNAME}"
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

post-extract:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/genmanlist.sh

post-patch:
	@${REINPLACE_CMD} -e 's,^OPT = -O,OPT =,' \
		${WRKSRC}/Makefile.in

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.post.mk>

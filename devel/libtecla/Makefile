# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libtecla
PORTVERSION=	1.6.2
CATEGORIES=	devel
MASTER_SITES=	http://www.astro.caltech.edu/~mcs/tecla/

MAINTAINER=	mike@fth-devel.net
COMMENT=	Interactive command line editing facilities

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
USE_SUBMAKE=	yes
ALL_TARGET=	default
USE_LDCONFIG=	yes
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		REALCURDIR="${.CURDIR}" \
		PORTNAME="${PORTNAME}"
MAKE_JOBS_UNSAFE=	yes
SSP_UNSAFE=	yes

NO_STAGE=	yes
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

# New ports collection makefile for:	rscheme
# Date created:				31 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rscheme
PORTVERSION=	0.7.3.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.rscheme.org/pub/rscheme/
DISTNAME=	rs-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${WRKDIR}/build ${CONFIGURE_TARGET}
MAKE_ENV=	REAL_PREFIX=${PREFIX}

BOOTSTRAP_DIR=	${WRKDIR}/${DISTNAME}
BOOTSTRAP_TARGET=	stage1

post-extract:
	@${MKDIR} ${WRKSRC} ${WRKDIR}/build

pre-configure:
	@${RM} -rf ${WRKSRC}
	@(cd ${BOOTSTRAP_DIR}; ${SETENV} ${MAKE_ENV} ${CONFIGURE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${BOOTSTRAP_TARGET})

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/build/bin/rs ${PREFIX}/bin/rs
	(cd ${WRKDIR}/build && ${TAR} -c -f - include/rscheme* lib/librs.a) \
		| (cd ${PREFIX} && ${TAR} --unlink -x -f -)
	${MKDIR} ${DATADIR}
	(cd ${WRKDIR}/build && ${TAR} -c -f - resource) \
		| (cd ${DATADIR} && ${TAR} --unlink -x -f -)

.include <bsd.port.mk>

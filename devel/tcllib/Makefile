# New ports collection makefile for: 	tcllib
# Date created:				27 Apr 2000
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=		tcllib
PORTVERSION= 		0.4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_TCLTK}
MASTER_SITE_SUBDIR=	tcllib
DISTNAME=		${PORTNAME}${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	mi@aldan.algebra.com

NO_BUILD=	YES

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MANN=	graph.n queue.n stack.n tree.n math.n ncgi.n pop3.n profiler.n html.n
MANCOMPRESSED=	no

do-install:
	${TAR} -xz --exclude "${PORTNAME}${PORTVERSION}/[RI]*" \
		-C ${LOCALBASE}/lib -f ${DISTDIR}/${DISTFILES}
	${MV} `find ${LOCALBASE}/lib/${PORTNAME}${PORTVERSION} \
			-type f -name '*.n'` \
		${LOCALBASE}/man/mann/

.include <bsd.port.mk>

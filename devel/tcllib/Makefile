# New ports collection makefile for: 	tcllib
# Date created:				27 Apr 2000
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=		tcllib
PORTVERSION=		0.8
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_TCLTK}
MASTER_SITE_SUBDIR=	tcllib
DISTNAME=		${PORTNAME}${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	mi@aldan.algebra.com

NO_BUILD=	YES

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MANN=	counter.n ftpd.n graph.n html.n javascript.n math.n \
	ncgi.n nntp.n pop3.n profiler.n queue.n stack.n textutil.n \
	tree.n uri.n
MANCOMPRESSED=	no

do-install:
	${TAR} -xpz --exclude "${PORTNAME}${PORTVERSION}/[RI]*" \
		--exclude install.sh \
		-C ${LOCALBASE}/lib -f ${DISTDIR}/${DISTFILES}
	${MV} `find ${LOCALBASE}/lib/${PORTNAME}${PORTVERSION} \
			-type f -name '*.n'` \
		${LOCALBASE}/man/mann/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

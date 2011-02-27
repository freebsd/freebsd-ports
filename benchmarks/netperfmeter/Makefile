# New ports collection makefile for: netperfmeter
# Date created:                      27 July 2010
# Whom:                              Thomas Dreibholz <dreibh@iem.uni-due.de>
#
# $FreeBSD$
#

PORTNAME=	netperfmeter
PORTVERSION=	1.1.7
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.iem.uni-due.de/~dreibh/netperfmeter/download/ http://www.exp-math.uni-essen.de/~dreibh/netperfmeter/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	Network Performance Meter

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/netperfmeter
MAN8=		netperfmeter.8

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
IGNORE=	not supported on systems earlier than 7.x
.endif

.include <bsd.port.post.mk>

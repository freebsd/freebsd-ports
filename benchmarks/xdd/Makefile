# New ports collection makefile for:	sysutils/xdd
# Date created:				29.05.2006
# Whom:					Gerhard Gonter <g.gonter@ieee.org>
#
# $FreeBSD$
#

PORTNAME=	xdd
PORTVERSION=	65
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.ioperformance.com/xddversions/
DISTNAME=	xdd65.013007
EXTRACT_SUFX=	.tgz

MAINTAINER=	g.gonter@ieee.org
COMMENT=	Tool for measuring and characterizing disk subsystem I/O

WRKSRC=		${WRKDIR}/${DISTNAME}
PLIST_FILES=	bin/xdd bin/timeserver bin/gettime
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(c|cpp|h)

post-extract:
	${CP} ${FILESDIR}/freebsd.makefile ${WRKSRC}

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} -f freebsd.makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xdd.freebsd ${PREFIX}/bin/xdd
	${INSTALL_PROGRAM} ${WRKSRC}/bin/timeserver.freebsd ${PREFIX}/bin/timeserver
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gettime.freebsd ${PREFIX}/bin/gettime

.include <bsd.port.mk>

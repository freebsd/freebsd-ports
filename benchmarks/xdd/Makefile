# Created by: Gerhard Gonter <g.gonter@ieee.org>
# $FreeBSD$

PORTNAME=	xdd
PORTVERSION=	65
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.ioperformance.com/xddversions/
DISTNAME=	xdd65.013007
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for measuring and characterizing disk subsystem I/O

WRKSRC=		${WRKDIR}/${DISTNAME}
PLIST_FILES=	bin/xdd bin/timeserver bin/gettime
USES=		dos2unix
DOS2UNIX_REGEX=	.*\.(c|cpp|h)
MAKEFILE=	freebsd.makefile

post-extract:
	${CP} ${FILESDIR}/freebsd.makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xdd.freebsd ${STAGEDIR}${PREFIX}/bin/xdd
	${INSTALL_PROGRAM} ${WRKSRC}/bin/timeserver.freebsd ${STAGEDIR}${PREFIX}/bin/timeserver
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gettime.freebsd ${STAGEDIR}${PREFIX}/bin/gettime

.include <bsd.port.mk>

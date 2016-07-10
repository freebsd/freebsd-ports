# $FreeBSD$

PORTNAME=	countdown
PORTVERSION=	20150606
CATEGORIES=	deskutils
MASTER_SITES=	http://acme.com/software/countdown/
DISTNAME=	${PORTNAME}_06jun2015

MAINTAINER=	neel@neelc.org
COMMENT=	Counts down a specified time interval, beeps, then exits

LICENSE=	BSD2CLAUSE

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/countdown man/man1/countdown.1.gz

MAKEFILE=	/dev/null
ALL_TARGET=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/countdown ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/countdown.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/countdown.1

.include <bsd.port.mk>

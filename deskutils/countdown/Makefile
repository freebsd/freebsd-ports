# $FreeBSD$

PORTNAME=	countdown
PORTVERSION=	20150606
CATEGORIES=	deskutils
MASTER_SITES=	https://acme.com/software/countdown/
DISTNAME=	${PORTNAME}_06jun2015

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Counts down a specified time interval, beeps, then exits

LICENSE=	BSD2CLAUSE

WRKSRC=		${WRKDIR}/countdown

PLIST_FILES=	bin/countdown \
		share/man/man1/countdown.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/countdown ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/countdown.1 ${STAGEDIR}${MAN1PREFIX}/share/man/man1/countdown.1

.include <bsd.port.mk>

PORTNAME=	countdown
PORTVERSION=	20220903
CATEGORIES=	deskutils
MASTER_SITES=	https://acme.com/software/countdown/
DISTNAME=	countdown_03Sep2022

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Counts down a specified time interval, beeps, then exits
WWW=		https://acme.com/software/countdown/

LICENSE=	ACME
LICENSE_NAME=	ACME Labs Freeware License
LICENSE_TEXT=	You may use this software however you like as long as you keep my name on it and don't sue me
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

WRKSRC=		${WRKDIR}/countdown

PLIST_FILES=	bin/countdown \
		share/man/man1/countdown.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/countdown ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/countdown.1 ${STAGEDIR}${PREFIX}/share/man/man1/countdown.1

.include <bsd.port.mk>

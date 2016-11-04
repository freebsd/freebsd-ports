# Created by: Jordan Hubbard <jkh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spegla
PORTVERSION=	1.1p5
DISTVERSIONPREFIX=	v
CATEGORIES=	ftp ipv6

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Mirror program for FTP sites (written in C)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	hrs-allbsd
LICENSE_BSD2CLAUSE_REGEX="/ \* [Cc]opyright/,/ \*\//!d;s,^ \*,,;s,^/,,"
MAKE_ARGS=	MANDIR=${MAN1PREFIX}/man/man
PLIST_FILES=	bin/spegla man/man1/spegla.1.gz
PORTEXAMPLES=	freebsd.org spegla.conf spegla.sh

OPTIONS_DEFINE=	IPV6
OPTIONS_DEFAULT=IPV6
IPV6_MAKE_ARGS=	-DINET6

post-extract:
	cd ${WRKSRC} && ${SED} -e ${LICENSE_BSD2CLAUSE_REGEX} \
	    ${WRKSRC}/spegla.c > ${LICENSE_FILE}

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/freebsd.org ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/spegla.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/spegla.sh ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

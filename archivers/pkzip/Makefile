# New ports collection makefile for:    pkzip
# Date created:         17 Mar 1999
# Whom:                 xxx
#
# $FreeBSD$
#

PORTNAME=	pkzip
PORTVERSION=	2.5
CATEGORIES=	archivers linux
MASTER_SITES=	ftp://ftp.pkware.com/
DISTNAME=	pklin251
EXTRACT_SUFX=	.exe

MAINTAINER=	dbader@eece.unm.edu

FORBIDDEN=	"security bug--see <URL:http://www.security.nnov.ru/advisories/archdt.asp> and <URL:http://cve.mitre.org/cgi-bin/cvename.cgi?name=CAN-2001-1270>"

BUILD_DEPENDS=	${LINUXBASE}/etc/redhat-release:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes

NO_BUILD=	Yes
NO_PACKAGE=	Shareware

STRIP=

do-extract:
	${MKDIR} ${WRKDIR}
	${MKDIR} ${WRKSRC}
	${CP} ${PORTSDIR}/distfiles/${DISTFILES} ${WRKSRC}/.
	${CHMOD} 700 ${WRKSRC}/${DISTFILES}
	cd ${WRKSRC} && \
	    ./${DISTFILES}

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} pkzip25 ${PREFIX}/bin

post-install:
	@${CAT} ${WRKSRC}/readme.txt

.include <bsd.port.mk>

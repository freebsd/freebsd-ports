# New ports collection makefile for:    stuffit
# Date created:		12 Dec 2001
# Whom:			Nathan Ahlstrom <nra@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stuffit
PORTVERSION=	5.2.0.611
CATEGORIES=	archivers linux
MASTER_SITES=	ftp://ftp.aladdinsys.com/pub/linux/StuffIt/ \
		ftp://ftp2.aladdinsys.com/pub/linux/StuffIt/ \
		ftp://ftp3.aladdinsys.com/pub/linux/StuffIt/ \
		ftp://ftp4.aladdinsys.com/pub/linux/StuffIt/
DISTNAME=	stuffit520.611linux-i386
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

NO_CDROM=	Shareware -- should not redistribute
NO_PACKAGE=	Only unmodified original package can be distributed

ONLY_FOR_ARCHS=	i386

USE_LINUX=	yes
NO_BUILD=	yes
STRIP=		# empty: do not strip linux binary during INSTALL_PROGRAM
WRKSRC=		${WRKDIR}
STUFFIT_FILES=	bin/unstuff bin/stuff
STUFFIT_MAN=    man/man1/stuff.1 man/man1/unstuff.1

MAN1 = stuff.1 unstuff.1

post-fetch:
	@${CHMOD} a+x ${DISTDIR}/${DISTFILES}

do-install:
.for sFile in ${STUFFIT_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${sFile} ${PREFIX}/bin
	brandelf -t Linux ${PREFIX}/${sFile}
.endfor
.for mFile in ${STUFFIT_MAN}
	${INSTALL_MAN} ${WRKSRC}/${mFile} ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>

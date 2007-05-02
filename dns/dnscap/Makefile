#
# Ports collection makefile for:	news/openftd
# Whom:					Edwin Groothuis <edwin@mavetju.org>
# Date created:				2007-05-02
#
# $FreeBSD$
#

PORTNAME=	dnscap
PORTVERSION=	0.0
CATEGORIES=	dns net
MASTER_SITES=	http://public.oarci.net/files/active/0/
DISTFILES=	dnscap.shar

MAINTAINER=	edwin@mavetju.org
COMMENT=	DNS traffic capture utility

WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/dnscap
MAN1=		dnscap.1

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${SH} ${DISTDIR}/${DISTFILES}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnscap ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dnscap.1 ${PREFIX}/man/man1

.include <bsd.port.mk>

# New ports collection makefile for:	webbench
# Date created:		10 Jan 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	webbench
PORTVERSION=	1.4
CATEGORIES=	benchmarks www
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/servers

MAINTAINER=	hsn@netmag.cz
COMMENT=	Simple forking web benchmark

USE_GETOPT_LONG=yes

MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		webbench.1
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	copyright changelog
.endif

PLIST_FILES=	bin/webbench

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/webbench ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
		${INSTALL_MAN} ${WRKSRC}/webbench.1 ${MAN1PREFIX}/man/man1
.endif
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/debian/copyright ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/debian/changelog ${DOCSDIR}
.endif

.include <bsd.port.mk>

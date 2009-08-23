# New ports collection makefile for:	packddir
# Date created:		2009-08-22
# Whom:			Ayumi M <ayu@commun.jp>
#
# $FreeBSD$
#

PORTNAME=	packddir
PORTVERSION=	0.0.6
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	upackddir_${PORTVERSION}-1

MAINTAINER=	ayu@commun.jp
COMMENT=	These trivial utilities can unpack and create PackdDir archives

WRKSRC=		${WRKDIR}/src

PLIST_FILES=	bin/upackddir
MAN1=		upackddir.1

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|$$(DESTDIR)/usr|${PREFIX}|' ${WRKSRC}/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/upackddir.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>

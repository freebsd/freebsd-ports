# New ports collection makefile for:	okphone
# Date created:		7 February 1996
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	okphone
PORTVERSION=	1.2
CATEGORIES=	japanese net
MASTER_SITES=	ftp://ftp.fit.ac.jp/pub/Net/okphone/

PATCH_SITES=	ftp://ftp.fit.ac.jp/pub/Net/okphone/patch/
PATCHFILES=	${DISTNAME}.FreeBSD-patch.rev2.gz

MAINTAINER=	max@FreeBSD.org
COMMENT=	Conference-calling phone with Japanese support

PATCH_DIST_STRIP=	-p1
MAN1=			phone.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/phone.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/okphone
.for f in NOTE READ_ME Readme.kana
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/okphone
.endfor
.endif
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

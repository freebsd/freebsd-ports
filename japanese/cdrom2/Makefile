# New ports collection makefile for:	cdrom2
# Date created:			03 Feb 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cdrom2
PORTVERSION=	1996.06.16
CATEGORIES=	japanese misc
MASTER_SITES=	ftp://ftp.nerimadors.or.jp/pub/src/cdrom2/
DISTNAME=	euc

MAINTAINER=	max@FreeBSD.org
COMMENT=	A tool to lookup CD-ROM dictionaries

WRKSRC=		${WRKDIR}/${PORTNAME}
DIST_SUBDIR=	${PORTNAME}
DOCS=		errata.doc gaiji.txt index.doc install.doc kekka.txt \
		kojien3.doc menu.doc readers.doc readme.doc readme.org \
		ruigo.doc x_option.doc

do-configure:
	@${ECHO_MSG} "Copying custom Makefile."
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/share/doc/cdrom2
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/cdrom2
.endfor
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>

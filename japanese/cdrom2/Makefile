# New ports collection makefile for:	cdrom2
# Version required:		1996/06/16
# Date created:			03 Feb 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	euc
PKGNAME=	ja-cdrom2-1996.06.16
CATEGORIES=	japanese misc
MASTER_SITES=	ftp://ftp.nerimadors.or.jp/pub/src/cdrom2/

MAINTAINER=	max@FreeBSD.org

WRKSRC=		${WRKDIR}/cdrom2
DIST_SUBDIR=	cdrom2
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
	@${CAT} ${PKGDIR}/MESSAGE
.endif

.include <bsd.port.mk>

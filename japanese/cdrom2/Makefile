# Created by: Masafumi NAKANE <max@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cdrom2
PORTVERSION=	1996.06.16
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://www.nerimadors.or.jp/~jiro/cdrom2/
DISTNAME=	euc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to lookup CD-ROM dictionaries

WRKSRC=		${WRKDIR}/${PORTNAME}
DIST_SUBDIR=	${PORTNAME}
DOCS=		errata.doc gaiji.txt index.doc install.doc kekka.txt \
		kojien3.doc menu.doc readers.doc readme.doc readme.org \
		ruigo.doc x_option.doc

SUB_FILES+=	pkg-message

NO_STAGE=	yes
do-configure:
	@${ECHO_MSG} "Copying custom Makefile."
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>

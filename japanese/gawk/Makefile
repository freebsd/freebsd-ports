# New ports collection makefile for:	gawk+mb
# Version required:	3.0.4+mb1.12
# Date created:		5 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

DISTNAME=	gawk-3.0.4
PKGNAME=	ja-gawk-3.0.4
CATEGORIES=	japanese lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gawk

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g

PATCH_SITES=	http://member.nifty.ne.jp/wills/program/
PATCHFILES=	gawkmb112.diff.gz
PATCH_DIST_STRIP=	-p1
FETCH_BEFORE_ARGS=	-b

MAN1=		gawk.1 igawk.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ja/awk
	${INSTALL_DATA} ${WRKSRC}/OREADME.MB ${PREFIX}/share/doc/ja/awk
	${INSTALL_DATA} ${WRKSRC}/README.MB ${PREFIX}/share/doc/ja/awk
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	grep+mb
# Date created:		2 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	grep
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	grep

PATCH_SITES=	ftp://ftp.hipecs.hokudai.ac.jp/pub/GNU/jp/
PATCHFILES=	${DISTNAME}-mb1.04.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
MAKE_ARGS=	binprefix=j

MAN1=		jgrep.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ja/grep
	${INSTALL_DATA} ${WRKSRC}/README.MB ${PREFIX}/share/doc/ja/grep
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	grep+mb
# Date created:		2 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	grep
PORTVERSION=	2.4.2
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

PATCH_SITES=	http://www.hinadori.dyn.to/~wills/program/
PATCHFILES=	grep-2.4.2-mlb2.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU grep + multi-byte extension

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=j --disable-nls

MAN1=		jgrep.1
MLINKS=		jgrep.1 jegrep.1 \
		jgrep.1 jfgrep.1

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.MB ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.mlb ${DOCSDIR}
.endif

.include <bsd.port.mk>

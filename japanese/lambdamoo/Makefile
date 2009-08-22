# New ports collection makefile for:	LambdaMOO
# Date created:		Jul 3 1999
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	lambdamoo
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	japanese net
MASTER_SITES=	SF\
		ftp://ftp.leo.chubu.ac.jp/pub/network/mnews/:MN

DISTNAME=	LambdaMOO-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mnews122.tar.gz:MN

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	flathill
PATCHFILES=	ja-lambdamoo-19990704.patch.gz

MAINTAINER=	ports@FreeBSD.ORG
COMMENT=	The most commonly used program to run MOOs

WRKSRC=		${WRKDIR}/MOO-${PORTVERSION}
GNU_CONFIGURE=	yes
ALL_TARGET=
DOCSDIR=	${PREFIX}/share/doc/LambdaMOO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/moo ${PREFIX}/sbin

pre-build:
.for i in kanjilib.c kanjilib.h
	${CP} ${WRKDIR}/mnews-1.22/kanjilib/$i ${WRKSRC}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC};\
	${INSTALL_MAN} Minimal.db README README.Minimal \
		${DOCSDIR}; \
	)
	@${INSTALL_DATA} ${FILESDIR}/README.FreeBSD \
		${DOCSDIR}
.endif

.include <bsd.port.mk>

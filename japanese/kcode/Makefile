# New ports collection makefile for:	kcode
# Date created:		26 October 2004
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	kcode
PORTVERSION=	1.0
CATEGORIES=	japanese
MASTER_SITES=	http://www.irori.org/dl/tool/
DISTFILES=	${PORTNAME}-${PORTVERSION}.gz
EXTRACT_ONLY=	${DISTFILES}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A handy utility to show codepoint information of given characters

RUN_DEPENDS=	${_RUN_DEPENDS}

USE_PERL5=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

MANLANG=	ja
MAN1=		kcode.1
MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		This port requires perl 5.6.0 or later
.elif ${PERL_LEVEL} < 500800
_RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode
.endif

do-extract:
	${MKDIR} ${WRKSRC}
	${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} > ${WRKSRC}/kcode
	pod2man ${WRKSRC}/kcode ${WRKSRC}/kcode.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/kcode ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/kcode.1 ${MAN1PREFIX}/man/ja/man1/

.include <bsd.port.post.mk>

# New ports collection makefile for:	Oniguruma
# Date created:		31 January 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	oniguruma
PORTVERSION=	2.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	contrib
DISTNAME=	onigd20040202
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A BSDL Regular Expressions library compatible with POSIX/GNU/Perl

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
#INSTALLS_SHLIB=	yes

DOCS=		HISTORY README doc/*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${EXAMPLESDIR}/
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>

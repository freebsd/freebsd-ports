# New ports collection makefile for:	Oniguruma
# Date created:		31 January 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	oniguruma
PORTVERSION=	1.7.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	contrib
DISTNAME=	onigd20030207
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
MAKEFILE=	BSDmakefile
MAKE_ARGS=	NOPROFILE=true
INSTALLS_SHLIB=	yes

DOCS=		README doc/*

pre-build:
	${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}/

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

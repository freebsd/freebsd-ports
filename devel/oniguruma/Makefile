# New ports collection makefile for:	Oniguruma
# Date created:		31 January 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	oniguruma
PORTVERSION=	1.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	contrib
DISTNAME=	onigd20030121
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
MAKEFILE=	BSDmakefile
MAKE_ARGS=	NOPROFILE=true
INSTALLS_SHLIB=	yes

pre-build:
	${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${EXAMPLESDIR}/
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>

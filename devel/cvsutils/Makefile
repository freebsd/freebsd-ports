# New ports collection makefile for:	cvsutils
# Date created:		6 June 2000
# Whom:			knu@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cvsutils
PORTVERSION=	2001.02.05
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu

MAINTAINER=	knu@FreeBSD.org

USE_AUTOMAKE=	YES
AUTOMAKE=	./bootstrap
USE_PERL5=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cvsutils
.for f in AUTHORS ChangeLog FAQ NEWS README TODO 
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/cvsutils/
.endfor
.endif

.include <bsd.port.mk>

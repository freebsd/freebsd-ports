# New ports collection makefile for:	cvsutils
# Date created:		6 June 2000
# Whom:			knu@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cvsutils
PORTVERSION=	2001.07.05
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu

MAINTAINER=	knu@FreeBSD.org

USE_AUTOMAKE_VER=15
AUTOMAKE_ARGS=	--add-missing
USE_PERL5=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}

pre-configure:
	cd ${WRKSRC} ; ${ACLOCAL}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS ChangeLog FAQ NEWS README TODO 
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>

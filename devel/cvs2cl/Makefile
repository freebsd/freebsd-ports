# New ports collection makefile for:	cvs2cl
# Date created:		6 June 2000
# Whom:			knu@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cvs2cl
PORTVERSION=	2.38
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu

MAINTAINER=	knu@FreeBSD.org

USE_PERL5=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}

DOCDIR=		${PREFIX}/share/doc/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README TODO index.html [cC]hange[lL]og* ${DOCDIR}
	${LN} -s ${PREFIX}/bin/${PORTNAME} ${DOCDIR}/${PORTNAME}.pl
.endif

.include <bsd.port.mk>

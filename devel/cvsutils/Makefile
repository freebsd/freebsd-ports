# New ports collection makefile for:	cvsutils
# Date created:		6 June 2000
# Whom:			knu@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cvsutils
PORTVERSION=	0.2.5
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.red-bean.com/cvsutils/releases/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	CVS utilities which facilitate working with local working directories

USE_PERL5=	yes
GNU_CONFIGURE=	yes

MAN1=		cvsutils.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	dparser
# Date created:			Nov 11, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dparser
PORTVERSION=	1.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	d-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple but powerful tool for parsing

WRKSRC=		${WRKDIR}/d
USE_GMAKE=	yes

MAN1=	make_dparser.1

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	blogbench
# Date created:			Feb 14, 2005
# Whom:				janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	blogbench
PORTVERSION=	1.0
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.blogbench.pureftpd.org/blogbench/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Performance Test of Filesystem I/O

GNU_CONFIGURE=	yes
USE_BZIP2=	yes

MAN8=		blogbench.8
PLIST_FILES=	bin/blogbench
PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

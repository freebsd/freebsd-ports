# New ports collection makefile for: 	newfile
# Date created:				Thu Jan 30 17:34:12 CET 2003
# Whom:					Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	newfile
PORTVERSION=	1.0.14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	A tool for creating starter files in various languages

USE_RUBY=	yes
GNU_CONFIGURE=	yes

MAN1=		newfile.1
DOCS=		doc/newfile.html

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/newfile.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

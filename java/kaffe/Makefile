# New ports collection makefile for:    kaffe
# Version required:     0.8.4
# Date created:         12 June 1997
# Whom:                 Mark Huizer <xaa@stack.nl>
#
# $Id: Makefile,v 1.23 1997/06/11 23:30:44 asami Exp $
#

DISTNAME=	kaffe-0.8.4
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.kaffe.org/pub/kaffe/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}.tgz kaffe-0.8.4-package-biss-net.com.tgz \
		kaffe-0.8.4-package-javasoft.com.tgz

MAINTAINER=	xaa@stack.nl

GNU_CONFIGURE=	yes
MAN1=		kaffe.1

post-install:
	${MKDIR} ${PREFIX}/share/kaffe
	${INSTALL_DATA} ${WRKSRC}/ENVIRONMENT ${WRKSRC}/license.terms ${PREFIX}/share/kaffe
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

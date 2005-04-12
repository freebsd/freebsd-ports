# Ports collection makefile for:	clisp-hyperspec
# Date created:				18 Aug 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	clisp-hyperspec
PORTVERSION=	7.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.lispworks.com/pub/software_tools/reference/
DISTNAME=	HyperSpec-7-0

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A Common Lisp reference in HTML format, from LispWorks Ltd

NO_CDROM=	Commercial redistribution prohibited

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

do-install:
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/* ${DOCSDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}

.include <bsd.port.mk>

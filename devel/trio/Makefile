# ex:ts=8
# New ports collection makefile for:	trio
# Date created:			Jun 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	trio
PORTVERSION=	1.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ctrio

MAINTAINER=	rainer.alves@gmail.com
COMMENT=	A fully matured and stable set of printf and string functions

GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${FIND} doc | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>

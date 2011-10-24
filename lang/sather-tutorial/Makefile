# New ports collection makefile for:		sather-tutorial
# Date created:			5 August 2006
# Whom:				Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	tutorial
PORTVERSION=	000328
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=sather/Doc
PKGNAMEPREFIX=	sather-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}.html

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tutorial on the Sather programming language

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
DOCSDIR=	${PREFIX}/share/doc/sather/${PORTNAME}

do-install:
	${MKDIR} ${DOCSDIR}
	@${TAR} -xzf ${DISTDIR}/${DISTFILES} -C ${DOCSDIR}
	@${FIND} ${DOCSDIR}/ -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}/

.include <bsd.port.mk>

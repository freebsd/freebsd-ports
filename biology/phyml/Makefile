# New ports collection makefile for:   phyml 3.0 20090706
# Date created:        July 17, 2009
# Whom:                ballen
#
# $FreeBSD$
#

PORTNAME=	phyml
PORTVERSION=	20090706
CATEGORIES=	biology
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	phyml_20090706

MAINTAINER=	ben@sysadminschronicles.com
COMMENT=	A simple, fast, and accurate algorithm to estimate large phylogenies

WRKSRC=		${WRKDIR}/${PORTNAME}/src
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/phyml
USE_AUTOTOOLS=	automake:110 aclocal:110
AUTOMAKE_ARGS=	--add-missing

.include <bsd.port.pre.mk>

pre-configure:
	${RM} ${WRKSRC}/missing

pre-install:
	${CHMOD} a+x ${WRKSRC}/install-sh

.include <bsd.port.post.mk>

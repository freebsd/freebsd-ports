# New ports collection makefile for:   swig13-doc
# Date created:        10 January 2003
# Whom:                eserte
#
# $FreeBSD$
#

PORTNAME=	swig-doc
PORTVERSION=	1.3.16
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	swig
DISTNAME=	swig-1.3.16

MAINTAINER=	slaven@rezic.de
COMMENT=	Simplified Wrapper and Interface Generator - Documentation

WRKSRC=		${WRKDIR}/${DISTNAME:U}

DOCSDIR=	${PREFIX}/share/doc/swig

do-configure:

do-build:

do-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${FIND} Examples Doc -type d \
		-exec ${INSTALL} -d ${DOCSDIR}/{} \;
	cd ${WRKSRC} && ${FIND} Examples Doc -type f \
		-exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;

.include <bsd.port.mk>

# New ports collection makefile for:	adns
# Date created:			Mon Mar 3, 2000
# Whom:				Kostya Lukin <lukin@okbmei.msk.su>
#
# $FreeBSD$
#

PORTNAME=	adns
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Easy to use asynchronous-capable DNS client library and utilities

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

LIBVERSION=	1
PLIST_SUB+=	LIBVERSION="${LIBVERSION}"

DOCS=		COPYING GPL-vs-LGPL INSTALL LICENCE.WAIVERS README README.html TODO changelog

post-install:
	${STRIP_CMD} ${PREFIX}/bin/adnslogres ${PREFIX}/bin/adnshost
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

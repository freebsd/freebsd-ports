# New ports collection makefile for:	adns
# Date created:			Mon Mar 3, 2000
# Whom:				Kostya Lukin <lukin@okbmei.msk.su>
#
# $FreeBSD$
#

PORTNAME=	adns
PORTVERSION=	1.2
CATEGORIES=	dns
MASTER_SITES=	ftp://ftp.chiark.greenend.org.uk/users/ian/adns/ \
		http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy to use, asynchronous-capable DNS client library and utilities

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes

LIBVERSION=	12
PLIST_SUB+=	LIBVERSION="${LIBVERSION}"

DOCS=		COPYING GPL-vs-LGPL INSTALL LICENCE.WAIVERS README README.html TODO changelog

post-install:
	${STRIP_CMD} ${PREFIX}/bin/adnslogres ${PREFIX}/bin/adnshost
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

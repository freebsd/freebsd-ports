# New ports collection makefile for:	dbdesigner
# Date created:				18 May 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dbdesigner
PORTVERSION=	0.p2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-p2

MAINTAINER=	anders@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_KDELIBS_VER=2

WRKSRC=		${WRKDIR}/${PORTNAME}

DOCS=	AUTHORS BUGS COPYING ChangeLog TODO

pre-configure:
	${PERL} -pi -e "s@#define KDEDIR.*@#define KDEDIR \"${LOCALBASE}\"@" \
		${WRKSRC}/dbdesign/dbdesign.h

.if !defined(NOPORTDOCS)
post-install:
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	viewcvs
# Date created:				Sun 02 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	viewcvs
PORTVERSION=	0.8
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

pre-install:
	@ ${PERL} -pi -e "s:${PREFIX}/viewcvs-dev:${PREFIX}/${PORTNAME}-${PORTVERSION}:g" \
	  ${WRKSRC}/viewcvs-install

do-install:
	@ cd ${WRKSRC} && ${PYTHON_CMD} viewcvs-install

post-install:
	@ ${SED} -e "s:%%PREFIX%%:${PREFIX}:g" pkg-message >${PKGMESSAGE}
.if !defined(BATCH)
	@ ${ECHO}
	@ ${CAT} ${PKGMESSAGE}
	@ ${ECHO}
.endif

.include <bsd.port.mk>

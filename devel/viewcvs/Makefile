# New ports collection makefile for:	viewcvs
# Date created:				Sun 02 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	viewcvs
PORTVERSION=	0.6
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

NO_BUILD=	yes

pre-install:
	${PERL} -pi -e "s:/usr/local/viewcvs-dev:${PREFIX}/share/viewcvs:g" ${WRKSRC}/viewcvs-install

do-install:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/python ${WRKSRC}/viewcvs-install)

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s:%%PREFIX%%:${PREFIX}:g"
	@${ECHO}

.include <bsd.port.mk>

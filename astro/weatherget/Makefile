# New ports collection makefile for:	weatherget
# Date created:		31 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	weatherget
PORTVERSION=	0.4.0.1
CATEGORIES=	astro
MASTER_SITES=	CENKES BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line weather reporting tool

DEPRECATED=	Broken b/c of weather.com new licensing rules not agreed by author
EXPIRATION_DATE=2011-11-04

USE_BZIP2=	yes
USE_PYTHON=	yes
NO_BUILD=	yes
PORTDOCS=	AUTHORS CHANGELOG README
PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e '/^#!/s|!.*|!${PYTHON_CMD}|' ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}/
.endif

.include <bsd.port.mk>

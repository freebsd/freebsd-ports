# New ports collection makefile for:	py-namebench
# Date created:				04 December 2009
# Whom:					Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	namebench
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	dns python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open-source DNS benchmark utility

MAKE_ENV+=	NO_THIRD_PARTY=yes

PORTDOCS=	README.txt

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_INSTALLARGS+=	--install-data=${PREFIX}/share

NO_INSTALL_MANPAGES=	yes

post-patch:
	@${REINPLACE_CMD} '/windows/d' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -o ${DOCOWN} -g ${DOCGRP} -m 555 -d ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

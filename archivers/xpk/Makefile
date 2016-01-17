# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	xpk
PORTVERSION=	0.1.4
PORTREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	http://vesuri.jormas.com/xpk/ \
		http://www.energyhq.es.eu.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The eXternal PacKer (XPK) library system

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxpk*.so

.include <bsd.port.mk>

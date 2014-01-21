# Created by: Rodrigo Graeff <delphus@gmail.com>
# $FreeBSD$

PORTNAME=	libytnef
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	devel mail
MASTER_SITES=	SF/ytnef/${PORTNAME}/${PORTVERSION}

MAINTAINER=	delphus@gmail.com
COMMENT=	Unpack data in MS Outlook TNEF format

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS NEWS README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

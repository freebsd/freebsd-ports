# Created by: Rodrigo Graeff <delphus@gmail.com>
# $FreeBSD$

PORTNAME=	libytnef
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	devel mail
MASTER_SITES=	SF/ytnef/${PORTNAME}/${PORTVERSION}

MAINTAINER=	delphus@gmail.com
COMMENT=	Unpack data in MS Outlook TNEF format

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS NEWS README

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

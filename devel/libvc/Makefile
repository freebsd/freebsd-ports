# Created by: Oliver Braun
# $FreeBSD$

PORTNAME=	libvc
PORTVERSION=	003
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/rolo/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	vCard library

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USES=		bison
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for DOC in AUTHORS ChangeLog NEWS README THANKS doc/rfc2426.txt
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

PORTNAME=	libvc
PORTVERSION=	003
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF/rolo/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	vCard library
WWW=		https://rolo.sourceforge.net/

USES=		bison:alias libtool tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for DOC in AUTHORS ChangeLog NEWS README THANKS doc/rfc2426.txt
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

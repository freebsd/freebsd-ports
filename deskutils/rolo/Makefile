# Created by: Andrew Hsu <ahsu@users.sf.net>
# $FreeBSD$

PORTNAME=	rolo
PORTVERSION=	011
CATEGORIES=	deskutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text-based contact management software

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvc.so:devel/libvc

USES=		localbase ncurses tar:bzip2
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for DOC in AUTHORS ChangeLog NEWS README THANKS
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

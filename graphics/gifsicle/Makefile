# Created by: Brad Hendrickse <bradh@iafrica.com>
# $FreeBSD$

PORTNAME=	gifsicle
PORTVERSION=	1.83
CATEGORIES=	graphics
MASTER_SITES=	http://www.lcdf.org/gifsicle/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Manipulates GIF images and animations

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

PORTDOCS=	NEWS README.md

OPTIONS_DEFINE=	X11 DOCS
OPTIONS_DEFAULT=X11

OPTIONS_SUB=	yes

X11_CONFIGURE_OFF=	--without-x --disable-gifview
X11_USE=	XORG=x11

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

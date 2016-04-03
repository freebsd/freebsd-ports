# Created by: Brad Hendrickse <bradh@iafrica.com>
# $FreeBSD$

PORTNAME=	gifsicle
PORTVERSION=	1.88
CATEGORIES=	graphics
MASTER_SITES=	http://www.lcdf.org/gifsicle/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Manipulates GIF images and animations

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PORTDOCS=	NEWS README.md
PLIST_FILES=	bin/gifdiff bin/gifsicle \
		man/man1/gifdiff.1.gz man/man1/gifsicle.1.gz

OPTIONS_DEFINE=		DOCS X11
OPTIONS_DEFAULT=	X11

X11_USE=		xorg=x11
X11_CONFIGURE_ENABLE=	gifview
X11_CONFIGURE_WITH=	x
X11_PLIST_FILES=	bin/gifview man/man1/gifview.1.gz

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

# Created by: johan
# $FreeBSD$

PORTNAME=	flphoto
PORTVERSION=	1.3.1
PORTREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	SF/fltk/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Basic image management and display program

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2 \
		libfltk.so:x11-toolkits/fltk \
		libpng.so:graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		tar:bzip2
USE_XORG=	xinerama
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|@OPTIM@|-DHAVE_CONFIG_H|g' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flphoto ${STAGEDIR}${PREFIX}/bin/flphoto
	${INSTALL_MAN} ${WRKSRC}/doc/flphoto.man ${STAGEDIR}${MAN1PREFIX}/man/man1/flphoto.1
	${INSTALL_MAN} ${WRKSRC}/doc/album.man ${STAGEDIR}${MAN5PREFIX}/man/man5/album.5
.for lang in de en_CA en_GB es fr it nl pt
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.po \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/flphoto_${lang}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.jpg ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

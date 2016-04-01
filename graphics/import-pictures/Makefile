# Created by: Alexander Kuehn
# $FreeBSD$

PORTNAME=	import-pictures
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.nagilum.org/unix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to copy/move pictures from a directory

BROKEN=		unfetchable

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-Time-modules>=0:devel/p5-Time-modules

USES=		gmake perl5 shebangfix tar:bzip2
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

PORTDOCS=	import-pictures.html

SHEBANG_FILES=	${WRKSRC}/${PORTNAME}
OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

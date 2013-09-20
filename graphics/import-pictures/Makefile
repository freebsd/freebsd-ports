# Created by: Alexander Kuehn
# $FreeBSD$

PORTNAME=	import-pictures
PORTVERSION=	1.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.nagilum.org/unix/

MAINTAINER=	freebsd@nagilum.org
COMMENT=	Utility to copy/move pictures from a directory

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Image-ExifTool>=0:${PORTSDIR}/graphics/p5-Image-ExifTool \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-Time-modules>=0:${PORTSDIR}/devel/p5-Time-modules

USE_BZIP2=	yes
USES=		gmake perl5

PLIST_FILES=	bin/${PORTNAME}

MAN1=		${PORTNAME}.1

PORTDOCS=	import-pictures.html

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>

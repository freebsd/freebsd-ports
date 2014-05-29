# Created by: Alexander Kuehn
# $FreeBSD$

PORTNAME=	import-pictures
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.nagilum.org/unix/

MAINTAINER=	freebsd@nagilum.org
COMMENT=	Utility to copy/move pictures from a directory

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Image-ExifTool>=0:${PORTSDIR}/graphics/p5-Image-ExifTool \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-Time-modules>=0:${PORTSDIR}/devel/p5-Time-modules

USES=		gmake perl5 shebangfix tar:bzip2

MAN1=		${PORTNAME}.1

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

PORTDOCS=	import-pictures.html

SHEBANG_FILES=	${WRKSRC}/${PORTNAME}
SHEBANG_LANG=	perl
OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${STAGEDIR}${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

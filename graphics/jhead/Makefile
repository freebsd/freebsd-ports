# Created by: Jamie Hermans <jamie@hermans.ca>

PORTNAME=	jhead
PORTVERSION=	3.06.0.1
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	EXIF JPEG header manipulation tool

LICENSE=	PD

USES=		gmake jpeg:run

MAKEFILE=	makefile

PLIST_FILES=	bin/jhead \
		share/man/man1/jhead.1.gz
PORTDOCS=	usage.html

GH_ACCOUNT=	Matthias-Wandel
USE_GITHUB=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS=/d' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/jhead.1 ${STAGEDIR}${PREFIX}/share/man/man1/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

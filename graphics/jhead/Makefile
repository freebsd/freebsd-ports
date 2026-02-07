PORTNAME=	jhead
PORTVERSION=	3.08
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	EXIF JPEG header manipulation tool
WWW=		https://github.com/Matthias-Wandel/jhead

LICENSE=	PD

USES=		cpe gmake jpeg:run

MAKEFILE=	makefile

PLIST_FILES=	bin/jhead \
		share/man/man1/jhead.1.gz

CPE_VENDOR=	jhead_project

GH_ACCOUNT=	Matthias-Wandel
USE_GITHUB=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/jhead.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>

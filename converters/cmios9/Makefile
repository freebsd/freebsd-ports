PORTNAME=	cmios9
PORTVERSION=	2.1
CATEGORIES=	converters
MASTER_SITES=	http://members.tripod.com/kmi9000/files/

MAINTAINER=	M.Indlekofer@gmx.de
COMMENT=	Ftp-like access to Fairlight image files and devices

PLIST_FILES=	bin/cmios9

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

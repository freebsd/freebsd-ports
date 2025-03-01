PORTNAME=	sqlitebrowser
DISTVERSIONPREFIX=	v
DISTVERSION=	3.13.1
CATEGORIES=	databases

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Visual tool to manage SQLite databases
WWW=		https://sqlitebrowser.org/

LICENSE=	MPL20 GPLv3+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE-GPL-3.0
LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE-MPL-2.0

USES=		cmake compiler:c++14-lang desktop-file-utils gnome qt:5 sqlite
USE_QT=		core concurrent gui network printsupport testlib widgets \
		buildtools:build linguisttools:build qmake:build xml
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/PreferencesDialog.cpp ${WRKSRC}/src/Application.cpp

.include <bsd.port.mk>

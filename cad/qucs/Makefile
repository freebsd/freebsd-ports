# $FreeBSD$

PORTNAME=	qucs
PORTVERSION=	0.0.19
PORTREVISION=	3
CATEGORIES=	cad science
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Graphical circuit design and simulation tool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/qucs/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BUILD_DEPENDS=	gperf:devel/gperf \
		admsXml:cad/adms

USE_QT=		moc_build uic_build rcc_build linguisttools_build \
		corelib gui xml svg script qt3support
USES=		autoreconf compiler:c++11-lib bison gmake libtool qt:4 shebangfix
SHEBANG_FILES=	qucs/contrib/ps2sp
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doc
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -name configure.ac -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e '/m4_esyscmd/ s|< VERSION|< ${WRKSRC}/VERSION|; s|git log|false|'

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/NEWS.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

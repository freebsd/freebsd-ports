PORTNAME=	ccmix
PORTVERSION=	g20170612
PORTREVISION=	2
CATEGORIES=	archivers games
MASTER_SITES=	SF/xccu/XCC%20Mixer/XCC%20Mixer%201.44:dat
DISTFILES=	XCC_Mixer-1.44.zip:dat

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Westwood Studios MIX format file manipulator
WWW=		https://github.com/OmniBlade/ccmix

LICENSE=	GPLv2+

LIB_DEPENDS=	libcryptopp.so:security/cryptopp

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	OmniBlade
GH_TAGNAME=	4369c8f

PLIST_FILES=	bin/ccmix bin/gmdedit bin/mixkey \
		${DATADIR_REL}/global\ mix\ database.dat
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/ccmix program usage/s,/n,\\n, ; \
		/gmd_dir/s,/usr/share/ccmix,${DATADIR},' \
			${WRKSRC}/src/ccmix.cpp
	@${REINPLACE_CMD} -e '/char2num/s,const static,& signed,' \
		${WRKSRC}/src/mixkey/mix_dexoder.cpp

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/build/* \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/global\ mix\ database.dat \
		${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${INSTALL_WRKSRC}/,} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

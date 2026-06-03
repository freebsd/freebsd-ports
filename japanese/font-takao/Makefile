PORTNAME=	takao
DISTVERSION=	003.03.01
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://launchpad.net/takao-fonts/trunk/15.03/+download/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	TakaoFonts_${DISTVERSION:S/.//}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${_EXNAME}${EXTRACT_SUFX}

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Improved IPA Japanese fonts
WWW=		https://launchpad.net/takao-fonts

LICENSE=	IPAFONTLICv1.0
LICENSE_NAME=	IPA Font License Agreement v1.0
LICENSE_FILE=	${WRKSRC}/IPA_Font_License_Agreement_v1.0.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts:fc tar:xz
FONTPATHSPEC=	${FONTNAME}:pri=60

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-install

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
PORTDOCS=	ChangeLog README README.ja

OPTIONS_DEFINE=	DOCS

_EXNAME=	TakaoExFonts_00201.01
_CONF=		20-unhint-${FONTNAME}.conf 62-fonts-${FONTNAME}.conf

post-extract:
	cd ${WRKSRC} && for F in *.ttf; do ${MV} $${F} $${F%.ttf}.otf; done
	cd ${WRKDIR}/${_EXNAME} && \
		for F in *.ttf; do ${MV} $${F} ${WRKSRC}/$${F%.ttf}.otf; done

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${_CONF:S,^,${FILESDIR}/,} \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${RLN} ${_CONF:S,^,../conf.avail/,} \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

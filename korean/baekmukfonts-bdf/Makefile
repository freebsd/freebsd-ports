PORTNAME=	baekmukfonts
PORTVERSION=	2.2
CATEGORIES=	korean x11-fonts
MASTER_SITES=	https://kldp.net/baekmuk/release/ \
		LOCAL/jkim
PKGNAMESUFFIX=	-bdf
DISTNAME=	865-baekmuk${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Baekmuk family Korean bitmap fonts
WWW=		https://kldp.net/baekmuk/

LICENSE=	Baekmuk
LICENSE_NAME=	Baekmuk
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=		fonts

FONTLIST=	batang10 batang10b batang12 batang12b batang14 batang14b \
		batang16 batang16b batang18 batang18b batang20 batang20b \
		batang24 batang24b \
		dotum10 dotum12 dotum14 dotum16 dotum18 dotum20 dotum24 \
		gulim10 gulim10b gulim12 gulim12b gulim14 gulim14b gulim16 \
		gulim16b gulim18 gulim18b gulim20 gulim20b gulim24 gulim24b \
		hline10 hline12 hline14 hline16 hline18 hline20 hline24

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/^865-//}

BDFTOPCF=	${PREFIX}/bin/bdftopcf

do-build:
.for f in ${FONTLIST}
	${BDFTOPCF} ${WRKSRC}/bdf/${f}.bdf | ${GZIP_CMD} -c > ${WRKDIR}/${f}.pcf.gz
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} COPYRIGHT COPYRIGHT.ks README \
	    ${WRKSRC}/bdf/fonts.alias ${WRKDIR}/*.pcf.gz ${STAGEDIR}${FONTSDIR})

.include <bsd.port.mk>

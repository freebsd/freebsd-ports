# Created by: Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
# $FreeBSD$

PORTNAME=	shinonome
PORTVERSION=	0.9.11.p1
PORTREVISION=	6
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://openlab.jp/efont/dist/shinonome/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
PKGNAMEPREFIX=	ja-font-
DISTNAME=	${PORTNAME:C/^font-//}-${PORTVERSION:C/.p/p/}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Shinonome Japanese fonts, 12/14/16 dots

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=		fonts tar:bzip2
NO_ARCH=	yes
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME:C/^font-//}-${PORTVERSION:C/.p.*$//}

PORTDOCS=	AUTHORS BUGS ChangeLog ChangeLog.0 DESIGN.12 DESIGN.14	\
		DESIGN.16 DESIGN.18 INSTALL README THANKS TODO LICENSE

FONTNAMES=\
	shnm6x12a    shnm6x12ab   shnm6x12ai   shnm6x12abi   \
	shnm6x12r    shnm6x12rb   shnm6x12ri   shnm6x12rbi   \
	shnm7x14a    shnm7x14ab   shnm7x14ai   shnm7x14abi   \
	shnm7x14r    shnm7x14rb   shnm7x14ri   shnm7x14rbi   \
	shnm8x16a    shnm8x16ab   shnm8x16ai   shnm8x16abi   \
	shnm8x16r    shnm8x16rb   shnm8x16ri   shnm8x16rbi   \
	shnm9x18a    shnm9x18ab   shnm9x18ai   shnm9x18abi   \
	shnm9x18r    shnm9x18rb   shnm9x18ri   shnm9x18rbi   \
	shnmk12      shnmk12b     shnmk12i     shnmk12bi     \
	shnmk12p     shnmk12pb    shnmk12pi    shnmk12pbi    \
	shnmk12min   shnmk12minb  shnmk12mini  shnmk12minbi  \
	shnmk12maru  shnmk12marub shnmk12marui shnmk12marubi \
	shnmk14      shnmk14b     shnmk14i     shnmk14bi     \
	shnmk14min   shnmk14minb  shnmk14mini  shnmk14minbi  \
	shnmk16      shnmk16b     shnmk16i     shnmk16bi     \
	shnmk16min   shnmk16minb  shnmk16mini  shnmk16minbi

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-build:
	@${ECHO_CMD} -n "Compressing PCF fonts"
	@cd ${WRKSRC} && for F in ${FONTNAMES}; do \
		${LOCALBASE}/bin/bdftopcf bdf/$${F}.bdf | \
		    ${GZIP_CMD} > $${F}.pcf.gz; \
		${ECHO_CMD} -n "."; \
	done
	@${ECHO_CMD} "Done"

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${FONTNAMES:C/$/.pcf.gz/} fonts.alias \
	    ${STAGEDIR}${FONTSDIR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

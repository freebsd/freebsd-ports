PORTNAME=	stonx
PORTVERSION=	0.6.7e.6
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	SF/stonx/stonx/0.6.7.6
DISTNAME=	STonX-0.6.7.6
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	AtariST emulator
WWW=		https://stonx.sourceforge.net/

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/share/emutos/etos512uk.img:${PKGCATEGORY}/emutos \
		bdftopcf:x11-fonts/bdftopcf \
		gccmakedep:devel/gccmakedep \
		mkfontscale:x11-fonts/mkfontscale \
		${LOCALBASE}/share/fonts/misc/10x20-ISO8859-1.pcf.gz:x11-fonts/font-misc-misc

USES=		fonts xorg
FONTNAME=	misc
USE_XORG=	x11 sm ice xext xorgproto
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CC="${CC}" CFLAGS="${CFLAGS}"
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib
ALL_TARGET=	all fnttobdf tosfonts fonts

BINDIR=	${PREFIX}/bin

DATA=	atari/bench1.pas atari/bench1.prg
ETCFILES=	keysyms-alternative keysyms-german keysyms-spanish
DOCS=	../COPYING AUTHORS DEBUGGING INSTALL README RELEASE_NOTES \
	TOS-VERSIONS
FONTS=	System0-iso.pcf System0.pcf System1-iso.pcf System1.pcf \
	System2-iso.pcf System2.pcf

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_DEFAULT=	UK
OPTIONS_RADIO=  TOS
OPTIONS_RADIO_TOS=	CZ DE ES FI FR GR HU IT NL NO RU SE SG TR UK US
CZ_DESC=	Czech (PAL)
DE_DESC=	German (PAL)
ES_DESC=	Spanish (PAL)
FI_DESC=	Finnish (PAL)
FR_DESC=	French (PAL)
GR_DESC=	Greek (PAL)
HU_DESC=	Hungarian (PAL)
IT_DESC=	Italian (PAL)
NL_DESC=	Dutch (PAL)
NO_DESC=	Norwegian (PAL)
PL_DESC=	Polish (PAL)
RO_DESC=	Romanian (PAL)
RU_DESC=	Russian (PAL)
SE_DESC=	Swedish (PAL)
SG_DESC=	Swiss German (PAL)
TR_DESC=	Turkish (PAL)
UK_DESC=	English (PAL)
US_DESC=	English (NTSC)

.include <bsd.port.options.mk>

pre-configure:
.for l in ${OPTIONS_RADIO_TOS}
.if ${PORT_OPTIONS:M${l}}
	${CP} -v ${LOCALBASE}/share/emutos/etos512${l:tl}.img ${WRKSRC}/data/tos.img
.endif
.endfor

post-install:
.for f in ${ETCFILES}
	${INSTALL_DATA} ${WRKSRC}/etc/$f ${STAGEDIR}${ETCDIR}/
.endfor
	@${ECHO_MSG} "===> Installing fonts"
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for f in ${FONTS}
	${INSTALL_DATA} ${WRKSRC}/data/$f ${STAGEDIR}${FONTSDIR}/
	${GZIP_CMD} ${STAGEDIR}${FONTSDIR}/$f
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${DATA:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>

PORTNAME=	dict
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	german
MASTER_SITES=	https://wolfram.schneider.org/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${dict}.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Simple English/German dictionary

LICENSE=	BSD2CLAUSE

NO_BUILD=	yes
PLIST_FILES=	bin/de-dict share/ger-eng.txt
dict=		ger-eng.txt

OPTIONS_DEFINE=
OPTIONS_DEFAULT=AGREP
OPTIONS_SINGLE=	GREP
OPTIONS_SINGLE_GREP=	AGREP UGREP
GREP_DESC=	grep with
AGREP_DESC=	use agrep
UGREP_DESC=	use ugrep
AGREP_RUN_DEPENDS=	agrep:textproc/agrep
UGREP_RUN_DEPENDS=	ugrep:textproc/ugrep

.include <bsd.port.options.mk>

post-extract: ${dict}

${dict}:
	${GZCAT} < ${DISTDIR}/${dict}.gz > ${WRKSRC}/${.TARGET}

do-configure:
.if ${PORT_OPTIONS:MAGREP}
	${REINPLACE_CMD} \
		-e 's|^agrep_opt=.*|agrep_opt="-V0 -i"|' \
		${WRKSRC}/dict.sh
.endif
.if ${PORT_OPTIONS:MUGREP}
	${REINPLACE_CMD} \
		-e 's|^agrep=.*|agrep="ugrep"|' \
		-e 's|^agrep_opt=.*|agrep_opt="--no-line-number -i"|' \
		-e 's| -B | --fuzzy=1 |' \
		${WRKSRC}/dict.sh
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dict.sh ${STAGEDIR}${PREFIX}/bin/de-dict
	${INSTALL_DATA} ${WRKSRC}/ger-eng.txt ${STAGEDIR}${PREFIX}/share/

.include <bsd.port.mk>

PORTNAME=	compdbgen
DISTVERSION=	g20250911
CATEGORIES=	devel

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	General-purpose tool for generating compile_commands.json files
WWW=		https://github.com/Virus-V/compdbgen

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Virus-V
GH_TAGNAME=	726a5c1d9b94650ced9dc13044e9459bc8780364
GH_TUPLE=	DaveGamble:cJSON:c859b25da02955fef659d658b8f324b5cde87be3:cJSONS/cjson

PLIST_FILES=	bin/${PORTNAME}

do-build:
		@cd ${WRKSRC}/ && ${SH} ./build.sh

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1400000
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-mainloop.c
.endif

.include <bsd.port.mk>

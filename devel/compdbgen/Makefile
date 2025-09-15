PORTNAME=	compdbgen
DISTVERSION=	g20250914
CATEGORIES=	devel

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	General-purpose tool for generating compile_commands.json files
WWW=		https://github.com/Virus-V/compdbgen

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Virus-V
GH_TAGNAME=	d839843448cbcf7ff394dcd32df586a0ab9aa156
GH_TUPLE=	DaveGamble:cJSON:c859b25da02955fef659d658b8f324b5cde87be3:cJSONS/cjson

PLIST_FILES=	bin/${PORTNAME}

do-build:
		@cd ${WRKSRC}/ && ${SH} ./build.sh

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

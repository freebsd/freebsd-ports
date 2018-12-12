# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	api-sanity-checker
PORTVERSION=	1.98.4
PORTREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	LOCAL/bf/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quickly generate sanity tests for the API of a C/C++ shared library

LICENSE=	LGPL20 GPLv2
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/abi-compliance-checker.pl:devel/abi-compliance-checker

USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}.pl
USE_GITHUB=	yes
GH_ACCOUNT=	lvc

.if defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
BUILD_DEPENDS=	${LOCALBASE}/bin/abi-compliance-checker.pl:devel/abi-compliance-checker
.else
USE_PERL5=	run
.endif
USE_GCC=	4.8 # same as devel/elfutils

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}.pl
PORTDOCS=	Changes.html Descriptor.html Options.html Readme.html \
		SpecType.html

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

CPPFILT?=	/usr/bin/c++filt
READELF?=	/usr/bin/readelf

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's/gcc([ \])/${CC}\1/' \
		-e 's/g\+\+([ \])/${CXX}\1/' \
		-e 's/ -shared/& ${PICFLAG}/' \
		-e 's|abi-compliance-checker|${LOCALBASE}/bin/&.pl|' \
		${WRKSRC}/${PORTNAME}.pl \
		${WRKSRC}/Makefile.pl \
		${WRKSRC}/modules/Internals/RegTests.pm

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

# XXX: tests fail: ERROR: can't find GCC>=3.0 in PATH
do-test:
	cd ${WRKSRC} && ${PERL} ./${PORTNAME}.pl -test

.include <bsd.port.mk>

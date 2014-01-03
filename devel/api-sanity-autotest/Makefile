# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	api-sanity-checker
PORTVERSION=	1.98.4
CATEGORIES=	devel perl5
MASTER_SITES=	https://github.com/lvc/${PORTNAME}/archive/ \
		LOCAL/bf/${DIST_SUBDIR}
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Quickly generate sanity tests for the API of a C/C++ shared library

LICENSE=	LGPL20 GPLv2
LICENSE_COMB=	dual

RUN_DEPENDS=	${LOCALBASE}/bin/abi-compliance-checker.pl:${PORTSDIR}/devel/abi-compliance-checker

USES=		perl5

.if defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
BUILD_DEPENDS=	${LOCALBASE}/bin/abi-compliance-checker.pl:${PORTSDIR}/devel/abi-compliance-checker
.else
USE_PERL5=	run
.endif
USE_GCC=	any

NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}.pl
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_STAGE=	yes
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
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin

.if defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
check regression-test test: build
	cd ${WRKSRC}; ${PERL} ./${PORTNAME}.pl -test

.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	Changes.html Descriptor.html Options.html Readme.html SpecType.html

post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc; ${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR})

.endif
.include <bsd.port.mk>

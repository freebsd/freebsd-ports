# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abi-compliance-checker
PORTVERSION=	1.99
CATEGORIES=	devel perl5
MASTER_SITES=	LOCAL/bf/${PORTNAME}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Checks binary compatibility of two versions of a C/C++ shared library

LICENSE=	LGPL20 GPLv2
LICENSE_COMB=	dual

USES=		perl5 shebangfix
SHEBANG_FILES=	*.pl
USE_GITHUB=	yes
GH_ACCOUNT=	lvc

.if defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
BUILD_DEPENDS?=	exctags:devel/ctags
.else
USE_PERL5=	run
.endif
RUN_DEPENDS?=	exctags:devel/ctags
USE_GCC=	any

NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}.pl

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

CPPFILT?=	/usr/bin/c++filt
CTAGS?=		exctags
GZ?=		/usr/bin/gzip
READELF?=	/usr/bin/readelf

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

PORTDATA=	*

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} \
		-e "\|get_CmdPath(\"c++filt\")|s|\"c++filt\"|\"${CPPFILT}\"|" \
		-e "\|get_CmdPath(\"ectags\")|s|\"ectags\"|\"${CTAGS}\"|" \
		-e "\|get_CmdPath(\"gcc\")|s|\"gcc\"|\"${CC}\"|" \
		-e "\|get_CmdPath(\"objdump\")|s|\"objdump\"|\"${OBJDUMP}\"|" \
		-e "\|get_CmdPath(\"readelf\")|s|\"readelf\"|\"${READELF}\"|" \
		-e "\|my \$$GzipCmd =|s|=.*|= \"${GZ}\";|" \
		-e "\|my \$$TarCmd =|s|=.*|= \"${TAR}\";|" \
		-e "\|TarCmd -xv.*>|{h; s| >.*|\");|; x; s|-xv|-t|; G;}" \
		-e "s|ACC_MODULES_INSTALL_PATH|${DATADIR}|" \
		${WRKSRC}/${PORTNAME}.pl
	@${SED} -i "" -e "\|BuildCmd|s|GCC_PATH.\"|& ${PICFLAG}|" \
		${WRKSRC}/modules/Internals/RegTests.pm

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \
	"modules/Internals modules/*.xml modules/Targets/unix" ${STAGEDIR}${DATADIR})

.if defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
check regression-test test: build
	cd ${WRKSRC}; \
	${PERL} ./${PORTNAME}.pl -test; \
	${PERL} ./${PORTNAME}.pl -test-dump

.endif

.include <bsd.port.mk>

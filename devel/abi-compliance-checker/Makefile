# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abi-compliance-checker
DISTVERSION=	2.0b1
PORTREVISION=	2
CATEGORIES=	devel perl5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Checks binary compatibility of two versions of a C/C++ shared library

LICENSE=	LGPL20 GPLv2
LICENSE_COMB=	dual

RUN_DEPENDS=	exctags:devel/ctags
RUN_DEPENDS+=	eu-readelf:devel/elfutils

OPTIONS_DEFINE=	DOCS PORTS_BINUTILS
PORTS_BINUTILS_DESC=	Use binutils from ports

USES=		gmake perl5 shebangfix
USE_PERL5=	run

USE_GITHUB=	nodefault
GH_TUPLE=	lvc:abi-compliance-checker:2.0b1 \
		lvc:vtable-dumper:0e04246:vdumper/vdumper \
		lvc:abi-dumper:46aae79:adumper/adumper \
		lvc:abi-compliance-checker:a6554a1:checker/checker
PLIST_FILES=	bin/${PORTNAME}.pl bin/abi-dumper.pl bin/vtable-dumper
SHEBANG_FILES=	checker/*.pl adumper/*.pl

PORTDATA=	*
PORTDOCS=	*

CTAGS?=		exctags

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPORTS_BINUTILS}
RUN_DEPENDS+=	readelf:devel/binutils
CPPFILT?=	${PREFIX}/bin/c++filt
READELF?=	${PREFIX}/bin/readelf
OBJDUMP?=	${PREFIX}/bin/objdump
.else
CPPFILT?=	/usr/bin/c++filt
.endif

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

do-build:
	cd ${WRKSRC}/vdumper && \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS}

post-patch:
	@${REINPLACE_CMD} \
		-e "\|get_CmdPath(\"c++filt\")|s|\"c++filt\"|\"${CPPFILT}\"|" \
		-e "\|get_CmdPath(\"ectags\")|s|\"ectags\"|\"${CTAGS}\"|" \
		-e "\|get_CmdPath(\"gcc\")|s|\"gcc\"|\"${CC}\"|" \
		-e "\|get_CmdPath(\"objdump\")|s|\"objdump\"|\"${OBJDUMP}\"|" \
		-e "\|get_CmdPath(\"readelf\")|s|\"readelf\"|\"${READELF}\"|" \
		-e "\|my \$$GzipCmd =|s|=.*|= \"${GZIP_CMD}\";|" \
		-e "\|my \$$TarCmd =|s|=.*|= \"${TAR}\";|" \
		-e "\|TarCmd -xv.*>|{h; s| >.*|\");|; x; s|-xv|-t|; G;}" \
		-e "s|ACC_MODULES_INSTALL_PATH|${DATADIR}|" \
		${WRKSRC}/checker/${PORTNAME}.pl
	@${SED} -i "" -e "\|BuildCmd|s|GCC_PATH.\"|& ${PICFLAG}|" \
		${WRKSRC}/checker/modules/Internals/RegTests.pm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vdumper/vtable-dumper \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/adumper/abi-dumper.pl \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/checker/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/checker/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/checker && ${COPYTREE_SHARE} \
		"modules/Internals modules/*.xml" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>

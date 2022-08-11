PORTNAME=	aros-sdk
PORTVERSION=	0.20060207
CATEGORIES=	devel
MASTER_SITES=	SF/aros/OldFiles
DISTNAME=	AROS-20060207-i386-all-sdk

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Software development kit (SDK) for the AROS Operating System

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	should work with a cross compiler, needs testing

USES=		gmake tar:bzip2

SUB_FILES=	pkg-message
SUB_LIST=	AROS_SDK_PATH=${AROS_SDK_PATH}

AROS_SDK_PATH=	${PREFIX}/aros-sdk

.include <bsd.port.pre.mk>

LD!=		${CC} -print-prog-name=ld
NM!=		${CC} -print-prog-name=nm
AS!=		${CC} -print-prog-name=as
AR!=		${CC} -print-prog-name=ar
OBJCOPY!=	${CC} -print-prog-name=objcopy
OBJDUMP!=	${CC} -print-prog-name=objdump
RANLIB!=	${CC} -print-prog-name=ranlib
STRIP!=		${CC} -print-prog-name=strip
CC_PROGRAMS_PATH!=${CC} -print-search-dirs | ${GREP} "programs: =" | cut -c 12-

CC_DIR!=dirname `which ${CC}`
.if ${CC_DIR} == "/usr/bin"
CC_INCLUDE=	/usr/include
.else
CCROOT!=	${DIRNAME} `${CC} -print-libgcc-file-name`
CC_INCLUDE:=	${CCROOT}/include
.endif

do-build:
	@${REINPLACE_CMD} -e 's|@aros_sdk_path@|${AROS_SDK_PATH}|g; s|@ld_emu@|elf_i386_fbsd|g; s|@cc_include@|${CC_INCLUDE}|g; s|@cc_cpu@|${ARCH}|g' ${WRKSRC}/scripts/specs.in
	@${REINPLACE_CMD} -e 's|@aros_sdk_path@|${AROS_SDK_PATH}|g; s|@ld@|${LD}|g; s|@nm@|${NM}|g; s|@cc@|${CC}|g; s|@objdump@|${OBJDUMP}|g; s|@cc_cpu@|${ARCH}|g; s|@strip@|${STRIP}|g' ${WRKSRC}/scripts/aros-gcc.in
	@${REINPLACE_CMD} -e 's|@aros_sdk_path@|${AROS_SDK_PATH}|g; s|@ld@|${LD}|g; s|@nm@|${NM}|g; s|@cc@|${CC}|g; s|@objdump@|${OBJDUMP}|g; s|@cc_cpu@|${ARCH}|g; s|@cc_programs_path@|${CC_PROGRAMS_PATH}|g' ${WRKSRC}/scripts/aros-ld.in
	@${REINPLACE_CMD} -e 's|@strip@|${STRIP}|g' ${WRKSRC}/scripts/aros-strip.in
	@cd ${WRKSRC}/tools/collect-aros; ${SETENV} ${MAKE_ENV} ${MAKE_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${AROS_SDK_PATH}
	@${MKDIR} ${STAGEDIR}${AROS_SDK_PATH}/bin
	@${MKDIR} ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/bin
	@${MKDIR} ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/include
	@${MKDIR} ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/lib/gcc-lib
	@${CP} ${WRKSRC}/tools/collect-aros/collect-aros ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/lib/gcc-lib/
	@${CP} ${WRKSRC}/scripts/specs.in ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/lib/gcc-lib/specs
	@${CP} ${WRKSRC}/scripts/aros-gcc.in ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/bin/gcc
	@${CHMOD} a+x ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/bin/gcc
	@${CP} ${WRKSRC}/scripts/aros-ld.in ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/bin/ld
	@${CHMOD} a+x ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/bin/ld
	@${CP} ${WRKSRC}/scripts/aros-strip.in ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/bin/strip
	@${CHMOD} a+x ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/bin/strip
	@${LN} -sf ${AS}      ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/bin/as
	@${LN} -sf ${AR}      ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/bin/ar
	@${LN} -sf ${NM}      ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/bin/nm
	@${LN} -sf ${OBJCOPY} ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/bin/objcopy
	@${LN} -sf ${OBJDUMP} ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/bin/objdump
	@${LN} -sf ${RANLIB}  ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/bin/ranlib
	@${LN} -sf ${AROS_SDK_PATH}/${ARCH}-aros/bin/gcc     ${STAGEDIR}${AROS_SDK_PATH}/bin/${ARCH}-aros-gcc
	@${LN} -sf ${AROS_SDK_PATH}/${ARCH}-aros/bin/ld      ${STAGEDIR}${AROS_SDK_PATH}/bin/${ARCH}-aros-ld
	@${LN} -sf ${AROS_SDK_PATH}/${ARCH}-aros/bin/ar      ${STAGEDIR}${AROS_SDK_PATH}/bin/${ARCH}-aros-ar
	@${LN} -sf ${AROS_SDK_PATH}/${ARCH}-aros/bin/as      ${STAGEDIR}${AROS_SDK_PATH}/bin/${ARCH}-aros-as
	@${LN} -sf ${AROS_SDK_PATH}/${ARCH}-aros/bin/nm      ${STAGEDIR}${AROS_SDK_PATH}/bin/${ARCH}-aros-nm
	@${LN} -sf ${AROS_SDK_PATH}/${ARCH}-aros/bin/objcopy ${STAGEDIR}${AROS_SDK_PATH}/bin/${ARCH}-aros-objcopy
	@${LN} -sf ${AROS_SDK_PATH}/${ARCH}-aros/bin/objdump ${STAGEDIR}${AROS_SDK_PATH}/bin/${ARCH}-aros-objdump
	@${LN} -sf ${AROS_SDK_PATH}/${ARCH}-aros/bin/ranlib  ${STAGEDIR}${AROS_SDK_PATH}/bin/${ARCH}-aros-ranlib
	@${LN} -sf ${AROS_SDK_PATH}/${ARCH}-aros/bin/strip   ${STAGEDIR}${AROS_SDK_PATH}/bin/${ARCH}-aros-strip
	@${CP} -pR ${WRKSRC}/${ARCH}/lib/*     ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/lib/
	@${CP} -pR ${WRKSRC}/${ARCH}/include/* ${STAGEDIR}${AROS_SDK_PATH}/${ARCH}-aros/include/

.include <bsd.port.post.mk>

PORTNAME=	fpc
PORTVERSION=	3.3.1.20260901
CATEGORIES=	lang
PKGNAMESUFFIX?=	-wasip1-devel
DIST_SUBDIR=	freepascal

MAINTAINER=	acm@FreeBSD.org
COMMENT?=	Free Pascal wasm wasip1 compiler (devel)
WWW=		https://www.freepascal.org/

CONFLICTS?=	fpc-wasip1threads-devel

RUN_DEPENDS=	${LOCALBASE}/bin/as:devel/binutils

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64 powerpc64le

USES+=		fpc gmake iconv
USE_BINUTILS=	yes
WANT_FPC_DEVEL=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.com/freepascal.org
GL_ACCOUNT=	fpc
GL_PROJECT=	source
GL_TAGNAME=	da47439dd51b003bc45f1ad41bd2ca24614d13f7

FPCOSTARGET=	${PKGNAMESUFFIX:S/-devel//:S/-//}
FPCSRCDIR=	source-${GL_TAGNAME}
FPCBASEVER=	3.3.1

PLIST_SUB=	PORTVERSION=${FPCBASEVER} \
		FPCOSTARGET=${FPCOSTARGET}

MAKE_ARGS=	OPT="-O-" \
		BSDHIER=1 \
		BINUTILSPREFIX="" \
		INSTALL="${INSTALL_DATA} -p" \
		INSTALLEXE="${INSTALL_PROGRAM}" \
		INSTALLSCR="${INSTALL_SCRIPT}" \
		INSTALL_PREFIX=${STAGEDIR}${PREFIX} \
		OS_TARGET=${FPCOSTARGET} \
		CPU_TARGET=wasm32 \
		PP=${LOCALBASE}/bin/fpc

do-extract:
# unpack source distribution
	@(cd ${WRKDIR} && ${GZIP_CMD} -dc \
		${_DISTDIR}/${PORTNAME}-source-${GL_TAGNAME}_GL0${EXTRACT_SUFX} | \
		${TAR} -xf -)

post-patch:
	@${REINPLACE_CMD} -i "" -e 's|900044|${OSVERSION}|g' \
				-e 's|1201000|${OSVERSION}|g' \
				-e 's|1200000|${OSVERSION}|g' \
				-e 's|1302001|${OSVERSION}|g' \
				-e 's|1500068|${OSVERSION}|g' \
		${WRKSRC}/rtl/freebsd/${FPC_ARCH}/*.as \
		${WRKSRC}/rtl/freebsd/${FPC_ARCH}/*.inc

.if empty(ICONV_LIB)
	@${REINPLACE_CMD} -i "" -e "s|s<>'c'|(s<>'c') and (s<>'iconv')|" \
			-e "s|%%FPC_LDPATH%%|${FPC_LDPATH}|g" \
				${WRKDIR}/${FPCSRCDIR}/compiler/systems/t_bsd.pas
	@${REINPLACE_CMD} -i "" -e 's|defined(bsd) and not ||' \
		${WRKDIR}/${FPCSRCDIR}/rtl/unix/cwstring.pp
.endif
	@${REINPLACE_CMD} -i "" -e '/samplecfg/ {s/INSTALLEXE/INSTALLSCR/;}' \
		${WRKDIR}/${FPCSRCDIR}/compiler/Makefile
	@${REINPLACE_CMD} -i "" -e 's|/usr/local|${PREFIX}|g' \
		${WRKDIR}/${FPCSRCDIR}/packages/fpmkunit/src/fpmkunit.pp
	@${REINPLACE_CMD} -i "" -e 's|$ifdef linux|$ifdef linux or $$ifdef freebsd|g' \
		${WRKSRC}/packages/opengles/src/gles20.pas

# enable units
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		${WRKSRC}/packages/a52/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		${WRKSRC}/packages/dts/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|freebsd,||g' \
		${WRKSRC}/packages/fpgtk/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|iphonesim|freebsd,iphonesim|g' \
		${WRKSRC}/packages/gnome1/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|iphonesim|freebsd,iphonesim|g' \
		${WRKSRC}/packages/gtk1/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|iphonesim|freebsd,iphonesim|g' \
		${WRKSRC}/packages/imlib/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		${WRKSRC}/packages/ldap/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		${WRKSRC}/packages/libnettle/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		${WRKSRC}/packages/libsee/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		${WRKSRC}/packages/lua/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		${WRKSRC}/packages/mad/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		${WRKSRC}/packages/modplug/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|Linux|freebsd,linux|g' \
		${WRKSRC}/packages/newt/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		${WRKSRC}/packages/oggvorbis/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		${WRKSRC}/packages/openal/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		-e 's|x86_64|x86_64,aarch64|g' \
			${WRKSRC}/packages/opencl/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		${WRKSRC}/packages/opengles/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		${WRKSRC}/packages/proj4/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|os2|freebsd,os2|g' \
		${WRKSRC}/packages/rexx/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		${WRKSRC}/packages/wasmedge/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		${WRKSRC}/packages/wasmtime/fpmake.pp
	@${REINPLACE_CMD} -i "" -e 's|linux|freebsd,linux|g' \
		${WRKSRC}/packages/zorba/fpmake.pp

do-build:
# build fpc compiler
	@${ECHO_MSG} "##### STARTING WASM32-WASIP1 CROSS-COMPILER AND UNITS #####"
		(cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} \
			crossall ${MAKE_ARGS})
		@${ECHO_MSG} "##### COMPLETE WASM32-WASIP1 CROSS-COMPILER AND UNITS #####"

do-install:
	# Installing the native wasm32-wasip1 cross-compiler and target units
		(cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} \
			crossinstall ${MAKE_ARGS})
		(cd ${STAGEDIR}${PREFIX}/bin && \
			${LN} -sf ../lib/fpc/${FPCBASEVER}/ppcrosswasm32 && \
			${LN} -sf ../lib/fpc/${FPCBASEVER}/ppcrosswasm32 ppcwasm32)

.include <bsd.port.mk>

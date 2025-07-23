PORTNAME=	fpc
PORTVERSION=	3.3.1.20250722
CATEGORIES=	lang
MASTER_SITES=	LOCAL/acm/freepascal/:bootstrap \
		LOCAL/acm/freepascal/:man
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	freepascal

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal compiler with Turbo and Delphi (devel)
WWW=		https://www.freepascal.org/

CONFLICTS=	fpc

RUN_DEPENDS=	${LOCALBASE}/bin/as:devel/binutils

ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES+=		gmake iconv
USE_BINUTILS=	yes
BOOTVER?=	3.2.2
FPCBASEVER=	3.3.1
MANVER=		3.2.2

FPC_LDPATH?=	"${LOCALBASE}/bin/ld.bfd"

USE_GITLAB=	yes
GL_SITE=	https://gitlab.com/freepascal.org
GL_ACCOUNT=	fpc
GL_PROJECT=	source
GL_TAGNAME=	9701f72a3f2162e690be0975a0df389c758ecdcc

FPCSRCDIR=	source-${GL_TAGNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
PPNAME=		ppc386
FPC_ARCH=	i386
PLIST_SUB+=	FPC_I386="" \
		FPC_AMD64="@comment " \
		FPC_AARCH64="@comment "
.elif ${ARCH} == "amd64"
PPNAME=		ppcx64
FPC_ARCH=	x86_64
PLIST_SUB+=	FPC_I386="@comment " \
		FPC_AMD64="" \
		FPC_AARCH64="@comment "
.elif ${ARCH} == "aarch64"
PPNAME=		ppca64
FPC_ARCH=	aarch64
PLIST_SUB+=	FPC_I386="@comment " \
		FPC_AMD64="@comment " \
		FPC_AARCH64=""
BOOTVER=	${FPCBASEVER}
MAKE_ARGS+=	OVERRIDEVERSIONCHECK=yes
.endif

.if ${OPSYS} == FreeBSD
PLIST_SUB+=	FREEBSD=""
.else
PLIST_SUB+=	FREEBSD="@comment "
.endif

SUB_FILES=	pkg-message

BUILDNAME=	${FPC_ARCH}-${OPSYS:tl}
PLIST_SUB+=	PORTVERSION=${FPCBASEVER} \
		BUILDNAME=${BUILDNAME}
DISTFILES+=	${BOOTDIR}.tar.gz:${OPSYS:MDragonFly}bootstrap \
		fpc-${MANVER}.man.tar.gz:man
NEWFPCMAKE=	${WRKDIR}/${FPCSRCDIR}/utils/fpcm/bin/${BUILDNAME}/fpcmake
MAKE_ARGS+=	FPCMAKE=${NEWFPCMAKE} \
		FPCTARGET=${BUILDNAME} \
		ARCH=${FPC_ARCH} \
		OPT="${OPT}" \
		BSDHIER=1 \
		INSTALL="${INSTALL_DATA} -p" \
		INSTALLEXE="${INSTALL_PROGRAM}" \
		INSTALLSCR="${INSTALL_SCRIPT}" \
		INSTALL_PREFIX=${STAGEDIR}${PREFIX} \
		FPC_LDPATH=${FPC_LDPATH}
NEWPPC=		PP=${WRKSRC}/compiler/${PPNAME}
NEWFPC=		FPC=${WRKSRC}/compiler/${PPNAME}
BOOTDIR=	${PPNAME}-${BOOTVER}-${OPSYS:tl}
BOOTPPC=	PP=${WRKDIR}/${BOOTDIR}

do-extract:
# unpack binary distribution
	@${MKDIR} ${WRKDIR}
	@${TAR} -xzf ${_DISTDIR}/${BOOTDIR}.tar.gz \
		--directory ${WRKDIR} && ${CHMOD} +x ${WRKDIR}/${BOOTDIR}
# unpack man files
	@${TAR} -xzf ${_DISTDIR}/fpc-${MANVER}.man.tar.gz --directory ${WRKDIR}
# unpack source distribution
	@(cd ${WRKDIR} && ${GZIP_CMD} -dc \
		${_DISTDIR}/${PORTNAME}-source-${GL_TAGNAME}_GL0${EXTRACT_SUFX} | \
		${TAR} -xf -)

post-patch:
.if ${OPSYS} == FreeBSD
	@${REINPLACE_CMD} -i "" -e 's|900044|${OSVERSION}|g' \
				-e 's|1201000|${OSVERSION}|g' \
				-e 's|1200000|${OSVERSION}|g' \
				-e 's|1302001|${OSVERSION}|g' \
				-e 's|1400097|${OSVERSION}|g' \
		${WRKSRC}/rtl/freebsd/${FPC_ARCH}/*.as \
		${WRKSRC}/rtl/freebsd/${FPC_ARCH}/*.inc
.else
	@${REINPLACE_CMD} -i "" -e 's|400000|${DFLYVERSION}|g' \
		${WRKSRC}/rtl/dragonfly/${FPC_ARCH}/*.as
.endif
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
	@${ECHO_MSG} "##### STARTING COMPILER AND UNITS #####"
	(cd ${WRKDIR}/${FPCSRCDIR} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} all ${MAKE_ARGS} ${BOOTPPC})
	@${ECHO_MSG} "##### COMPLETE COMPILER AND UNITS #####"

do-install:
	# Installing fpc compiler
	(cd ${WRKDIR}/${FPCSRCDIR} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} install ${MAKE_ARGS} ${BOOTPPC})

	# Installing manpages
	${INSTALL_MAN} ${WRKDIR}/man/man1/* ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKDIR}/man/man5/* ${STAGEDIR}${PREFIX}/share/man/man5
	# symlinking compiler
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} -sf ../lib/fpc/${FPCBASEVER}/${PPNAME})
	# creating sample configuration file
	${SH} "${STAGEDIR}${PREFIX}/lib/fpc/${FPCBASEVER}/samplecfg" \
		"${STAGEDIR}${PREFIX}/lib/fpc/${FPCBASEVER}" \
		"${STAGEDIR}${PREFIX}/etc"
	@${REINPLACE_CMD} -i "" -e 's|${STAGEDIR}||' \
		-e 's|^#-Fl/lib;/usr/lib|-Fl${LOCALBASE}/lib;${LOCALBASE}/lib/qt5;${LOCALBASE}/lib/qt6|g' \
			${STAGEDIR}${PREFIX}/etc/fpc.cfg.sample \
			${STAGEDIR}${PREFIX}/etc/fppkg.cfg.sample \
			${STAGEDIR}${PREFIX}/etc/fppkg/default \
			${STAGEDIR}${PREFIX}/lib/fpc/${FPCBASEVER}/ide/text/fp.cfg

.include <bsd.port.post.mk>

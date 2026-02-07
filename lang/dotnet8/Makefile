DISTVERSION=	${DOTNETVERSION}.20
PKGNAMESUFFIX=	8

SHEBANG_FILES=	src/source-build-externals/src/azure-activedirectory-identitymodel-extensions-for-dotnet/updateAssemblyInfo.sh

DOTNET_ENV=	PATH=${PATH}:${LLVM_PREFIX}/bin

BOOTSTRAP_DOTNETVERSION=	8.0
BOOTSTRAP_SDKVERSION=		${BOOTSTRAP_DOTNETVERSION}.120
BOOTSTRAP_SDKVERSIONSUFFIX=	-servicing.25421.1

DOTNETVERSION=			8.0
SDKVERSION=			${DOTNETVERSION}.120
SDKVERSIONSUFFIX=		-servicing.25323.1
SDK_RID=			freebsd-${DOTNET_ARCH}

DOTNET_BUILD_SH_EXTRA_FLAGS=
ARTIFACTS_SUBDIR=	/artifacts/${DOTNET_ARCH}/Release

MASTERDIR=	${.CURDIR}/../dotnet
PATCHDIR=	${.CURDIR}/files
DISTINFO_FILE=	${.CURDIR}/distinfo
PLIST=		${.CURDIR}/pkg-plist

# https://github.com/dotnet/dotnet/issues/4037
post-patch:
	${CP} ${PATCHDIR}/0003-Fix-assembly-version-calculation-in-2026.patch \
		${WRKSRC}/src/source-build-externals/patches/azure-activedirectory-identitymodel-extensions-for-dotnet/

.include	"${MASTERDIR}/Makefile"

# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	monodevelop
PORTVERSION=	7.6.11.7
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	mono@FreeBSD.org
COMMENT=	IDE for the .NET platform

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	msbuild:devel/msbuild \
		fsharpc:lang/fsharp \
		cmake:devel/cmake
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libssh2.so:security/libssh2
RUN_DEPENDS=	${LOCALBASE}/lib/libgdiplus.a:x11-toolkits/libgdiplus \
		exctags:devel/ctags \
		git:devel/git \
		svn:devel/subversion \
		fsharpc:lang/fsharp

# main/external/fsharpbinding/paket.lock
NUGET_FEEDS=	NUGET ROSLYN ROSLYN_FOR_VS_FOR_MAC  TEMPLATING VS_IMPL VS_EDITOR VSSDK VSTEST
NUGET_LAYOUT=	legacy
VS_IMPL_URL=	https://vside.myget.org/F/vs-impl/api/v2/
VS_EDITOR_URL=	https://www.myget.org/F/vs-editor/api/v2/
VSSDK_URL=	https://vside.myget.org/F/vssdk/api/v2/
PAKET_DEPENDS=	ExtCore=0.8.46 \
		FAKE=4.61.1 \
		FSharp.Compiler.CodeDom=0.9.2 \
		FSharp.Compiler.Service=23.0.1 \
		FSharp.Core=4.3.3 \
		Fantomas=2.6.1 \
		Mono.Cecil=0.10.0-beta6 \
		Newtonsoft.Json=10.0.3 \
		StrongNamer=0.0.6 \
		System.Collections.Immutable=1.3.1 \
		System.Reactive.Core=3.1.1 \
		System.Reactive.Interfaces=3.1.1 \
		System.Reactive.Linq=3.1.1 \
		System.Reflection.Metadata=1.4.2 \
		System.ValueTuple=4.4.0
PAKET_PACKAGEDIR=${WRKSRC}/external/fsharpbinding/packages

USES=		autoreconf desktop-file-utils gettext gmake gnome mono:nuget pathfix pkgconfig shared-mime-info ssl
USE_GNOME=	gtksharp20 gnomesharp20
INSTALLS_ICONS=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release --disable-update-mimedb --disable-update-desktopdb \
		--enable-maintainer-mode --enable-gnomeplatform --enable-git
INSTALL=	/usr/bin/install
USE_GITHUB=	yes
GH_ACCOUNT=	mono
GH_TUPLE=	icsharpcode:RefactoringEssentials:0148f6a:1/external/RefactoringEssentials \
		mono:debugger-libs:cd477ba:3/external/debugger-libs \
		mono:guiunit:dd094e7:4/external/guiunit \
		mono:libgit-binary:d8b2aca:6/external/libgit-binary \
		mono:libgit2:e8b8948:7/external/libgit2 \
		mono:libgit2sharp:319fa36:8/external/libgit2sharp \
		mono:mono-addins:293cbf2:9/external/mono-addins \
		icsharpcode:NRefactory:0607a4a:10/external/nrefactory \
		mono:nuget-binary:ebedbf8:11/external/nuget-binary \
		mono:xwt:cacc327:12/external/xwt

INSTALL_TARGET=	install-strip
MAKE_ENV=	DOTNET_MSBUILD_SDK_RESOLVER_SDKS_DIR= \
		XDG_CACHE_HOME=${WRKDIR} \
		OPENSSL_ROOT_DIR=${OPENSSLBASE}
MAKE_JOBS_UNSAFE=Build parallelization not implemented
WRKSRC_SUBDIR=	main
PORTSCOUT=	limit:^\d+\.\d+\.[1-9].*

.include <bsd.port.pre.mk>

BROKEN=			checksum and size mismatch
DEPRECATED=	Broken for more than 3 months
EXPIRATION_DATE=	2020-01-10
.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	fails to compile: incomplete definition of type 'struct bio_st'
BROKEN_FreeBSD_13=	fails to compile: incomplete definition of type 'struct bio_st'
.elif ${SSL_DEFAULT} == openssl111
BROKEN=			fails to compile: incomplete definition of type 'struct bio_st'
.endif

post-patch:
	${ECHO} "Release ID: ${PORTVERSION}" > ${WRKSRC}/buildinfo

.include <bsd.port.post.mk>

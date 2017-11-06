# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	monodevelop
PORTVERSION=	6.2.1.3
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	devel

MAINTAINER=	mono@FreeBSD.org
COMMENT=	IDE for the .NET platform

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	mautil:devel/mono-addins \
		fsharpc:lang/fsharp \
		cmake:devel/cmake \
		referenceassemblies-pcl>=0:lang/referenceassemblies-pcl
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libssh2.so:security/libssh2
RUN_DEPENDS=	${LOCALBASE}/lib/libgdiplus.a:x11-toolkits/libgdiplus \
		exctags:devel/ctags \
		mautil:devel/mono-addins \
		git:devel/git \
		svn:devel/subversion \
		fsharpc:lang/fsharp

NUGET_DEPENDS=	ExtCore=0.8.46 \
		FSharp.Compiler.CodeDom=0.9.2 \
		FSharp.Compiler.Service=8.0.0 \
		FSharp.Core=4.0.0.1 \
		Fantomas=2.5.0 \
		Microsoft.AspNet.Mvc=5.2.3 \
		Microsoft.AspNet.Razor=3.2.3 \
		Microsoft.AspNet.WebPages=3.2.3 \
		Microsoft.CodeAnalysis=1.3.2 \
		Microsoft.CodeAnalysis.Analyzers=1.1.0 \
		Microsoft.CodeAnalysis.CSharp=1.3.2 \
		Microsoft.CodeAnalysis.CSharp.Workspaces=1.3.2 \
		Microsoft.CodeAnalysis.Common=1.3.2 \
		Microsoft.CodeAnalysis.VisualBasic=1.3.2 \
		Microsoft.CodeAnalysis.VisualBasic.Workspaces=1.3.2 \
		Microsoft.CodeAnalysis.Workspaces.Common=1.3.2 \
		Microsoft.Composition=1.0.27 \
		Microsoft.Web.Infrastructure=1.0.0.0 \
		NUnit=2.6.4 \
		NUnit.Engine=3.0.1 \
		NUnit.Runners=2.6.4 \
		NuGet.Build.Packaging=0.1.248 \
		Newtonsoft.Json=8.0.3 \
		SharpZipLib=0.86.0 \
		System.Collections.Immutable=1.3.1 \
		System.Reflection.Metadata=1.2.0

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release --disable-update-mimedb --disable-update-desktopdb \
		--enable-maintainer-mode --enable-gnomeplatform --enable-git
USE_GITHUB=	yes
GH_ACCOUNT=	mono
GH_TUPLE=	icsharpcode:RefactoringEssentials:70e434d:1/external/RefactoringEssentials \
		mono:cecil:cd2ff63:2/external/cecil \
		mono:debugger-libs:256d90d:3/external/debugger-libs \
		mono:guiunit:2670780:4/external/guiunit \
		mono:ikvm-fork:94d4a29:5/external/ikvm \
		mono:libgit-binary:d8b2aca:6/external/libgit-binary \
		mono:libgit2:e8b8948:7/external/libgit2 \
		mono:libgit2sharp:06bbc96:8/external/libgit2sharp \
		mono:mono-addins:1919a2e:9/external/mono-addins \
		icsharpcode:NRefactory:a2b55de:10/external/nrefactory \
		mono:nuget-binary:58f8910:11/external/nuget-binary \
		mono:xwt:f981e41:12/external/xwt

USES=		autoreconf desktop-file-utils gettext gmake mono:nuget pathfix shared-mime-info ssl
USE_GNOME=	gtksharp20 gnomesharp20
INSTALLS_ICONS=	yes

INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	Build parallelization not implemented
WRKSRC_SUBDIR=		main
PORTSCOUT=	limit:^\d+\.\d+\.[1-9]\d*

post-extract:
	@${LN} -Fs ${NUGET_PACKAGEDIR} ${WRKSRC}/external/fsharpbinding/packages

post-patch:
	${REINPLACE_CMD} 's/0.1.157-dev/0.1.248/g' \
		${WRKSRC}/src/addins/MonoDevelop.Packaging/MonoDevelop.Packaging/DotNetProjectExtensions.cs \
		${WRKSRC}/src/addins/MonoDevelop.Packaging/PostBuild.proj \
		${WRKSRC}/src/addins/MonoDevelop.Packaging/Templates/CrossPlatformLibrary.xpt.xml \
		${WRKSRC}/src/addins/MonoDevelop.Packaging/Templates/PackagingProject.xpt.xml \
		${WRKSRC}/src/addins/MonoDevelop.Packaging/packages.config
	${LN} -Fs ${WRKSRC}/packages/System.Collections.Immutable.1.3.1 \
		${WRKSRC}/packages/System.Collections.Immutable.1.1.37
	${ECHO} "Release ID: ${PORTVERSION}" > ${WRKSRC}/buildinfo

.include <bsd.port.mk>

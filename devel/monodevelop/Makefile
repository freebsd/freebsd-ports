# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	monodevelop
PORTVERSION=	6.1.2.44
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

NUGET_DEPENDS=  ExtCore=0.8.45 \
		FSharp.Compiler.CodeDom=0.9.2 \
		FSharp.Compiler.Service=3.0.0 \
		FSharp.Core=4.0.0.1 \
		Fantomas=2.4.0 \
		Microsoft.AspNet.Mvc=5.2.3 \
		Microsoft.AspNet.Razor=3.2.3 \
		Microsoft.AspNet.WebPages=3.2.3 \
		Microsoft.Web.Infrastructure=1.0.0.0 \
		NUnit=2.6.4 \
		NUnit.Engine=3.0.1 \
		NUnit.Runners=2.6.4 \
		Newtonsoft.Json=6.0.8

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release --disable-update-mimedb --disable-update-desktopdb \
		--enable-maintainer-mode --enable-gnomeplatform --enable-git
USE_GITHUB=	yes
GH_TUPLE=	mono:${PORTNAME}:${PORTNAME}-${PORTVERSION} \
		icsharpcode:RefactoringEssentials:cbd2d9e:RefactoringEssentials \
		mono:cecil:cd2ff63:cecil \
		mono:debugger-libs:4a74b2c:debugger_libs \
		mono:guiunit:2670780:guiunit \
		mono:ikvm-fork:94d4a29:ikvm \
		mono:libgit-binary:d8b2aca:libgit_binary \
		mono:libgit2:e8b8948:libgit2 \
		mono:libgit2sharp:06bbc96:libgit2sharp \
		mono:mono-addins:76cab2d:mono_addins \
		icsharpcode:NRefactory:a2b55de:nrefactory \
		mono:nuget-binary:0811ba8:nuget_binary \
		mono:roslyn:16e117c:roslyn \
		mono:xwt:9ee2853:xwt

USES=		autoreconf desktop-file-utils gettext gmake mono:nuget pathfix shared-mime-info ssl
USE_GNOME=	gtksharp20 gnomesharp20
INSTALLS_ICONS=	yes

INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	Build parallelization not implemented
WRKSRC_SUBDIR=		main
PORTSCOUT=	limit:^\d+\.\d+\.[1-9]\d*

post-extract:
.for tuple in ${GH_TUPLE}
.  if ${PORTNAME} != ${tuple:C/([^:]*):([^:]*):([^:]*)/\2/}
	@${RMDIR} ${WRKSRC}/external/${tuple:C/[^:]+:([^:]+):([^:]+):([^:]+)/\3/:S/_/-/g}
	@${MV} ${WRKDIR}/${tuple:C/[^:]+:([^:]+):([^:]+):([^:]+)/\1-\2/} \
		${WRKSRC}/external/${tuple:C/[^:]+:([^:]+):([^:]+):([^:]+)/\3/:S/_/-/g}
.  endif
.endfor
	@${LN} -s ${NUGET_PACKAGEDIR} ${WRKSRC}/external/fsharpbinding/packages

post-patch:
	${REINPLACE_CMD} 's|mono .nuget/NuGet.exe restore|${TRUE}|' ${WRKSRC}/Makefile.am
	${ECHO} "Release ID: ${PORTVERSION}" > ${WRKSRC}/buildinfo

.include <bsd.port.mk>

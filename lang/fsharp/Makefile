# Created by: Phillip Neumann <pneumann@gmail.com>
# $FreeBSD$

PORTNAME=	fsharp
PORTVERSION=	4.0.1.10
CATEGORIES=	lang
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Functional and object-oriented language for the .NET platform

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mono>=3.0:lang/mono \
		referenceassemblies-pcl>=4.6-1:lang/referenceassemblies-pcl
RUN_DEPENDS=	mono>=3.0:lang/mono

NUGET_DEPENDS=	FSharp.Compiler.Tools-4.0.1.3 \
		FSharp.Data-2.2.5 \
		FSharp.SRGen.Build.Tasks-3.0.0 \
		fssrgen-3.0.0 \
		Microsoft.DiaSymReader-1.0.8 \
		Microsoft.DiaSymReader.PortablePdb-1.1.0 \
		System.Collections.Immutable-1.2.0 \
		System.Reflection.Metadata-1.4.1-beta-24227-04

USE_GITHUB=	yes

USES=		autoreconf gmake mono pkgconfig
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	Build not parallelizable
NO_ARCH=	yes

NUGET_PACKAGEDIR=	${WRKSRC}/packages

.for depend in ${NUGET_DEPENDS}
id=		${depend:C/-.*$//}
version=	${depend:C/^[^-]*-//}
group=		nuget_${id:S/.//g}
nupkg=		${id:tl}.${version}.nupkg
DISTFILES_${group}:=	${nupkg}:${group}
MASTER_SITES_${group}:=	https://www.nuget.org/api/v2/package/${id}/${version}?dummy=/:${group}
NUGET_NUPKGS_${group}:=	${nupkg}:${id}-${version}

DISTFILES+=	${DISTFILES_nuget_${depend:C/-.*$//:S/.//g}}
MASTER_SITES+=	${MASTER_SITES_nuget_${depend:C/-.*$//:S/.//g}}
NUGET_NUPKGS+=	${NUGET_NUPKGS_nuget_${depend:C/-.*$//:S/.//g}}
.endfor

post-extract:
.for nupkg in ${NUGET_NUPKGS}
	@${MKDIR} ${NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S/-/./}
	@tar -xf ${DISTDIR}/${nupkg:C/:.*$//} -C ${NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S/-/./} \
		-s/%2B/\+/g -s/%2B/\+/g -s/%2B/\+/g \
		--exclude '\[Content_Types\].xml' \
		--exclude package/ \
		--exclude _rels/
.endfor

do-test:
	${MKDIR} ${WRKDIR}/bin
	echo "#!/bin/sh" > ${WRKDIR}/bin/fsharpc
	echo 'exec ${LOCALBASE}/bin/mono ${WRKSRC}/lib/release/fsc.exe "$$@"' >> ${WRKDIR}/bin/fsharpc
	${CHMOD} 0755 ${WRKDIR}/bin/fsharpc
	(cd ${WRKSRC}/tests/fsharp/core; \
		${ENV} \
			PATH=${WRKDIR}/bin:${PATH} \
			MONO_PATH=${WRKSRC}/lib/release \
			./run-all.sh)

.include <bsd.port.mk>

# Created by: David Naylor <dbn@dragon.local>
# $FreeBSD$

PORTNAME=	referenceassemblies-pcl
PORTVERSION=	4.6
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://download.microsoft.com/download/B/7/9/B79993DE-10E7-457A-B22B-4A918086A989/:ms \
		http://download.mono-project.com/repo/debian/pool/main/r/referenceassemblies-pcl/:mono
DISTFILES=	NetFx_PortableLibraryReferenceAssemblies46.exe:ms \
		referenceassemblies-pcl_2014.04.14.orig.tar.bz2:mono

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Microsoft .Net Portable Class Library Reference Assemblies

LICENSE=	EULA
LICENSE_NAME=	Microsoft software license terms for Microsoft .Net Portable Class Library Reference Assemblies - 4.6
LICENSE_FILE=	${FILESDIR}/EULA.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

EXTRACT_DEPENDS=	cabextract:archivers/cabextract

NO_BUILD=	yes
NO_ARCH=	yes
PLIST_SUB=	PKGNAME=${PKGNAME}

NETPORTABLEDIR=	lib/mono/xbuild-frameworks/.NETPortable
PRADIR=		PortableReferenceAssemblies-2014-04-14/

do-extract:
.for file in u4 a1
	cabextract -d ${WRKDIR} -F ${file} ${DISTDIR}/NetFx_PortableLibraryReferenceAssemblies46.exe
.endfor
	${MV} ${WRKDIR}/u4 ${WRKDIR}/EULA.rtf
	cabextract -d ${WRKDIR} ${WRKDIR}/a1
	${RM} ${WRKDIR}/a1

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${NETPORTABLEDIR}
# XXX: tar(1)'s 'g' flag is broken on FreeBSD<11.
#      Repeat the pattern as a workaround.
	tar -xC ${STAGEDIR}${PREFIX}/${NETPORTABLEDIR} -f ${WRKDIR}/PortableReferenceAssemblies.zip \
		-s'|\\|/|g' \
		-s'|\\|/|g' \
		-s'|\\|/|g' \
		-s'|\\|/|g'
	tar -xC ${STAGEDIR}${PREFIX}/${NETPORTABLEDIR} -f ${DISTDIR}/referenceassemblies-pcl_2014.04.14.orig.tar.bz2 \
		-s'|${PRADIR}||g' \
		--include ${PRADIR}v4.0/Profile/Profile102 \
		--include ${PRADIR}v4.0/Profile/Profile225 \
		--include ${PRADIR}v4.0/Profile/Profile240 \
		--include ${PRADIR}v4.0/Profile/Profile255 \
		--include ${PRADIR}v4.0/Profile/Profile328 \
		--include ${PRADIR}v4.0/Profile/Profile336 \
		--include ${PRADIR}v4.0/Profile/Profile344 \
		--include ${PRADIR}v4.0/Profile/Profile92 \
		--include ${PRADIR}v4.5/Profile/Profile111 \
		--include ${PRADIR}v4.5/Profile/Profile259 \
		--include ${PRADIR}v4.6/Profile/Profile151 \
		--include ${PRADIR}v4.6/System.Runtime.WindowsRuntime.UI.Xaml.dll \
		--include ${PRADIR}v4.6/System.Runtime.WindowsRuntime.dll \
		--include '*/Windows 8.xml' \
		--include '*/Windows 8.1.xml' \
		--include '*/Windows Phone Silverlight 8.xml'
	${MKDIR} ${STAGEDIR}${PREFIX}/share/licenses/${PKGNAME}
	${INSTALL_DATA} ${WRKDIR}/EULA.rtf ${STAGEDIR}${PREFIX}/share/licenses/${PKGNAME}/EULA.rtf

.include <bsd.port.mk>

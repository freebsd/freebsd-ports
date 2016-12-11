# Created by: Vladimir Kondratiev <wulf@mail.mipt.ru>
# $FreeBSD$

PORTNAME=	fuse-roms
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	ftp://mirror.switch.ch/pool/4/mirror/rpmfusion/${FC_SUBDIR}/:1 \
		ftp://ftp.ntua.gr/pub/linux/rpmfusion/${FC_SUBDIR}/:1 \
		ftp://ftp.pbone.net/mirror/rpmfusion.org/${FC_SUBDIR}/:1 \
		ftp://ftp.icm.edu.pl/vol/rzm5/linux-rpmfusion/${FC_SUBDIR}/:1 \
		http://zxspectrum.it.omegahg.com/rom/:2 \
		https://rene-ladan.nl/distfiles/
DISTFILES=	fuse-emulator-roms-0.9.0-6.fc${FCVER}.noarch.rpm:1,DEFAULT \
		Opus-22.rom:2,DEFAULT
EXTRACT_ONLY=	fuse-emulator-roms-0.9.0-6.fc${FCVER}.noarch.rpm

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Spectrum ROM files, for use with the Fuse emulator

LICENSE=	NONE

FCVER=		25
FC_SUBDIR=	nonfree/fedora/releases/${FCVER}/Everything/x86_64/os/Packages/f
NO_ARCH=	yes
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/fuse

ROMS=		128p-0.rom 128p-1.rom 256s-0.rom 256s-1.rom 256s-2.rom \
		256s-3.rom gluck.rom if1-1.rom if1-2.rom opus.rom trdos.rom
PLIST_FILES=	${ROMS:S|^|%%DATADIR%%/|}

RESTRICTED=	No explicit permission to redistribute

OPTIONS_DEFINE=	DOCS

DOCS_PLIST_FILES=${DOCSDIR_REL}/rom-distribution.txt

post-extract:
	${CP} ${DISTDIR}/Opus-22.rom ${WRKDIR}/usr/share/fuse/opus.rom

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKDIR}/usr/share/fuse && \
		${INSTALL_DATA} ${ROMS} ${STAGEDIR}${DATADIR})
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/usr/share/doc/fuse-emulator-roms && \
		${INSTALL_DATA} rom-distribution.txt ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

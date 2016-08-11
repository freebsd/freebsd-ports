# Created by: Vladimir Kondratiev <wulf@mail.mipt.ru>
# $FreeBSD$

PORTNAME=	fuse-roms
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	ftp://mirror.switch.ch/pool/4/mirror/rpmfusion/nonfree/fedora/releases/${FCVER}/Everything/x86_64/os/:1 \
		ftp://ftp.ntua.gr/pub/linux/rpmfusion/nonfree/fedora/releases/${FCVER}/Everything/x86_64/os/:1 \
		ftp://ftp.pbone.net/mirror/rpmfusion.org/nonfree/fedora/releases/${FCVER}/Everything/x86_64/os/:1 \
		ftp://ftp.icm.edu.pl/vol/rzm2/linux-rpmfusion/nonfree/fedora/releases/${FCVER}/Everything/x86_64/os/:1 \
		https://rene-ladan.nl/distfiles/:2
DISTFILES=	fuse-emulator-roms-0.9.0-6.fc${FCVER}.noarch.rpm:1 Opus-22.rom:2
EXTRACT_ONLY=	fuse-emulator-roms-0.9.0-6.fc${FCVER}.noarch.rpm

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Spectrum ROM files, for use with the Fuse emulator

FCVER=		22
PORTSCOUT=	ignore:1
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

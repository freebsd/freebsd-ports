# Created by: Vladimir Kondratiev <wulf@mail.mipt.ru>
# $FreeBSD$

PORTNAME=	fuse-roms
PORTVERSION=	0.9.0
CATEGORIES=	emulators
MASTER_SITES=	ftp://mirror.switch.ch/pool/4/mirror/rpmfusion/nonfree/fedora/releases/19/Everything/x86_64/os/:1 \
		ftp://ftp.ntua.gr/pub/linux/rpmfusion/nonfree/fedora/releases/19/Everything/x86_64/os/:1 \
		ftp://ftp.pbone.net/mirror/rpmfusion.org/nonfree/fedora/releases/19/Everything/x86_64/os/:1 \
		ftp://ftp.icm.edu.pl/vol/rzm2/linux-rpmfusion/nonfree/fedora/releases/19/Everything/x86_64/os/:1 \
		http://zxspectrum.it.omegahg.com/rom/:2
DISTNAME=	fuse-emulator-roms-0.9.0-5.fc19.noarch.rpm:1 Opus-22.rom:2
EXTRACT_SUFX=
EXTRACT_ONLY=	fuse-emulator-roms-0.9.0-5.fc19.noarch.rpm

MAINTAINER=	wulf@mail.mipt.ru
COMMENT=	Spectrum ROM files, for use with the Fuse emulator

PORTSCOUT=	ignore:1
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/fuse

ROMS=		128p-0.rom 128p-1.rom 256s-0.rom 256s-1.rom 256s-2.rom \
		256s-3.rom gluck.rom if1-1.rom if1-2.rom opus.rom trdos.rom
PLIST_FILES=	${ROMS:S|^|%%DATADIR%%/|}
PLIST_DIRSTRY=	%%DATADIR%%

RESTRICTED=	No explicit permission to redistribute

post-extract:
	${CP} ${DISTDIR}/Opus-22.rom ${WRKDIR}/usr/share/fuse/opus.rom

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKDIR}/usr/share/fuse && \
		${INSTALL_DATA} ${ROMS} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

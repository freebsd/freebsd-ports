PORTNAME=	fuse-roms
PORTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.pbone.net/mirror/rpmfusion.org/${FC_SUBDIR}/:1 \
		https://gitlab.com/menelkir/fuseroms/-/raw/main/fuse/:2
DISTFILES=	fuse-emulator-roms-${PORTVERSION}-${FCREV}.fc${FCVER}.noarch.rpm:1 \
		opus.rom:2
EXTRACT_ONLY=	fuse-emulator-roms-${PORTVERSION}-${FCREV}.fc${FCVER}.noarch.rpm

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Spectrum ROM files, for use with the Fuse emulator

LICENSE=	NONE
# No explicit permission to redistribute

FCREV=		16
FCVER=		35
FC_SUBDIR=	nonfree/fedora/releases/${FCVER}/Everything/x86_64/os/Packages/f
NO_ARCH=	yes
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/fuse

ROMS=		128p-0.rom 128p-1.rom 256s-0.rom 256s-1.rom 256s-2.rom \
		256s-3.rom gluck.rom if1-1.rom if1-2.rom opus.rom trdos.rom
PLIST_FILES=	${ROMS:S|^|${DATADIR_REL}/|}

OPTIONS_DEFINE=	DOCS

DOCS_PLIST_FILES=${DOCSDIR_REL}/rom-distribution.txt

post-extract:
	${CP} ${DISTDIR}/opus.rom ${WRKDIR}/usr/share/fuse/

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKDIR}/usr/share/fuse && \
		${INSTALL_DATA} ${ROMS} ${STAGEDIR}${DATADIR})
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/usr/share/doc/fuse-emulator-roms && \
		${INSTALL_DATA} rom-distribution.txt ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

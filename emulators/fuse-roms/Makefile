PORTNAME=	fuse-roms
DISTVERSION=	0.2
PORTEPOCH=	1
CATEGORIES=	emulators

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Spectrum ROM files, for use with the Fuse emulator
WWW=		https://sourceforge.net/projects/fuse-emulator/

LICENSE=	NONE
# No explicit permission to redistribute

USE_GITLAB=	yes
GL_ACCOUNT=	menelkir
GL_PROJECT=	fuseroms
GL_COMMIT=	fed6cfca1d13acad86a0802bfbd4b8af3a42d688
NO_ARCH=	yes
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/fuse

ROMS=		128-spanish-0.rom 128-spanish-1.rom \
		128p-0.rom 128p-1.rom \
		256s-0.rom 256s-1.rom 256s-2.rom 256s-3.rom \
		gluck.rom \
		if1-1.rom if1-2.rom \
		opus.rom \
		trdos.rom \
		disk_plus3.szx \
		tape_128.szx \
		tape_16.szx \
		tape_2048.szx \
		tape_2068.szx \
		tape_48.szx \
		tape_pentagon.szx \
		tape_plus2.szx \
		tape_plus2a.szx \
		tape_plus3.szx \
		tape_plus3e.szx \
		tape_scorpion.szx \
		tape_se.szx \
		tape_ts2068.szx

PLIST_FILES=	${ROMS:S|^|${DATADIR_REL}/|}

OPTIONS_DEFINE=	DOCS

DOCS_PLIST_FILES=${DOCSDIR_REL}/rom-distribution.txt

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/fuse-extra && \
		${INSTALL_DATA} ${ROMS} ${STAGEDIR}${DATADIR})
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && \
		${INSTALL_DATA} rom-distribution.txt ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

PORTNAME=	stb
DISTVERSION=	g20251026 # the upstream has no intension to have repo tagging
PORTEPOCH=	1
CATEGORIES=	devel

PATCH_SITES=	https://github.com/nothings/${PORTNAME}/commit/
PATCHFILES=	3d401e71452d890eaf0bc50b11788cb08a6c2fed.patch:-p1 \
		5818c4e48a7e7d4c21aacf3cd6f1c7e12f770924.patch:-p1 \
		49c16b0c2a4efa72d0ce6ea05d3fa7d9e8fc6cba.patch:-p1 \
		f9a5eaee846f1a19fbcda2f5adb5238a94cbbc2f.patch:-p1 \
		5cf3af3181f7a0fb8d59ca5fe8daa011c1918d19.patch:-p1 \
		4e58258d8c434111fe2e8f1146ae0a72b0e8c554.patch:-p1 \
		d66d0fe8c1a6ed393817791e4376374fa7f4ecc1.patch:-p1 \
		8cfcbf7dde7705c849f4f7a5acb26f79b895fffe.patch:-p1 \
		973cdc889deaae2b97d1bdf9b793b96be02b9b3c.patch:-p1 \
		20f77a9b7f53624014e8c7224eeb182674111bcb.patch:-p1 \
		a15dded5ca5ebb4ca18e553349f2b3f9594484d6.patch:-p1 \
		3866f62442b559603208f5d378cd60cd509c48b8.patch:-p1 \
		746d207256ef408d92112a13a75aa8a42df6753f.patch:-p1 \
		3741e6fea656d3f1b9578d59f14d8945aea92a10.patch:-p1 \
		724a10527964762fde9e79f38413aed4166b456e.patch:-p1 \
		accdaeec436156fb4876c31e99530e2029e33c0f.patch:-p1 \
		3846f7cb6fd8c8fa216602b8a34cf0f888f71044.patch:-p1 \
		78714f6106cf2a95ec832a5bb7b4872d4d1c1b3b.patch:-p1 \
		1024af37158286b6a149c8b08307cfd056a6403b.patch:-p1 # the list of PRs is in https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=293344#c0

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Stb single-file public domain libraries for C/C++
WWW=		https://github.com/nothings/stb/

LICENSE=	MIT PD
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE
LICENSE_FILE_PD=	${WRKSRC}/LICENSE

USES=		cpe
CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	nothings
GH_TAGNAME=	f1c79c02

NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	stb.pc
SUB_LIST=	PREFIX=${PREFIX} DISTVERSION=${DISTVERSION:S|g||g}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC} && ${INSTALL_DATA} *.c *.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/stb.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>

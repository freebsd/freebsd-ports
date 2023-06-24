PORTNAME=	tla
PORTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU/gnu-arch \
		http://www.atai.org/gnuarch/releases/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Original arch source control management CLI written in C
WWW=		https://www.gnu.org/software/gnu-arch/

LICENSE=	GPLv2+

BUILD_DEPENDS=	gpatch:devel/patch \
		gdiff:textproc/diffutils \
		gtar:archivers/gtar
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake pkgconfig ssl

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-gnu-patch gpatch \
		--with-gnu-diff gdiff \
		--with-gnu-diff3 gdiff3 \
		--with-gnu-tar gtar
CONFIGURE_ENV=	ne_cv_libsfor_SSL_library_init=yes

MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	test

PATCH_WRKSRC=	${ORIGWRKSRC}/..
WRKSRC=		${ORIGWRKSRC}/=build

OPTIONS_DEFINE=	DOCS

ORIGWRKSRC=	${WRKDIR}/${DISTNAME}/src

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CPPFLAGS+=       -Wno-error=int-conversion
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CPPFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

pre-install:
	${RM} -r ${ORIGWRKSRC}/docs-tla/PLUGIN \
		${ORIGWRKSRC}/docs-tla/{arch} ${ORIGWRKSRC}/docs-tla/.arch-ids

do-install:
	${INSTALL_PROGRAM} ${ORIGWRKSRC}/=build/tla/tla/tla ${STAGEDIR}${PREFIX}/bin
	${SED} 's,^#!.*$$,#!${AWK} -f,' ${ORIGWRKSRC}/tla/=gpg-check.awk \
		> ${WRKDIR}/tla-gpg-check
	${INSTALL_SCRIPT} ${WRKDIR}/tla-gpg-check ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${ORIGWRKSRC}/docs-tla && ${FIND} . -name '*.html' | \
		${CPIO} -pdm -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

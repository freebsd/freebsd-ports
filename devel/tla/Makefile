# Ports collection makefile for:	tla
# Date Created:			August 17th, 2003
# Whom:				seanc
#
# $FreeBSD$
#

PORTNAME=	tla
PORTVERSION=	1.3.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		http://regexps.srparish.net/src/${PORTNAME}/ \
		http://arch.quackerhead.com/~lord/releases/${PORTNAME}/
MASTER_SITE_SUBDIR=	gnu-arch

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	The original arch source control management CLI written in C

BUILD_DEPENDS=	gpatch:${PORTSDIR}/devel/patch \
		gdiff:${PORTSDIR}/textproc/diffutils \
		gtar:${PORTSDIR}/archivers/gtar
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

ORIGWRKSRC=	${WRKDIR}/${DISTNAME}/src
PATCH_WRKSRC=	${ORIGWRKSRC}/..
WRKSRC=		${ORIGWRKSRC}/=build
PLIST=		${WRKDIR}/plist
PLIST_FILES=	bin/tla bin/tla-gpg-check bin/awiki

pre-patch:
	${MKDIR} ${WRKSRC}

do-configure:
	cd ${WRKSRC} ; ../configure --prefix ${LOCALBASE} \
			--with-gnu-patch gpatch \
			--with-gnu-diff gdiff \
			--with-gnu-diff3 gdiff3 \
			--with-gnu-tar gtar

test:
	cd ${WRKSRC} ; ${GMAKE} test

pre-install:
.if !defined(NOPORTDOCS)
	${RM} -rf ${ORIGWRKSRC}/docs-tla/PLUGIN ${ORIGWRKSRC}/docs-tla/{arch} \
	${ORIGWRKSRC}/docs-tla/.arch-ids
	cd ${ORIGWRKSRC}/docs-tla && ${FIND} .  -type f -name '*.html' -exec ${ECHO_CMD} "%%DOCSDIR%%/{}" \; > ${PLIST}
	cd ${ORIGWRKSRC}/docs-tla && ${FIND} -d . -mindepth 1 -maxdepth 1 -type d -exec ${ECHO_CMD} "@dirrm %%DOCSDIR%%/{}" \; >> ${PLIST}
	${ECHO} @dirrm %%DOCSDIR%% >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${ORIGWRKSRC}/=build/tla/tla/tla ${PREFIX}/bin
	${INSTALL_PROGRAM} ${ORIGWRKSRC}/=build/awiki/awiki/awiki ${PREFIX}/bin
	${SED} 's,^#!.*$$,#!${AWK} -f,' ${ORIGWRKSRC}/tla/=gpg-check.awk \
		> ${WRKDIR}/tla-gpg-check
	${INSTALL_SCRIPT} ${WRKDIR}/tla-gpg-check ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${ORIGWRKSRC}/docs-tla && ${FIND} . -name '*.html' | ${CPIO} -pdm -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	${CHMOD} -R a=rX ${DOCSDIR}
.endif

.include <bsd.port.mk>

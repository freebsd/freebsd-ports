# New ports collection makefile for:   rogue_s
# Date created:		3 December 1998
# Whom:			Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	rogue_s
PORTVERSION=	1.3a
CATEGORIES=	japanese games
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		${MASTER_SITE_PORTS_JP:S,/%SUBDIR%/,/,}
MASTER_SITE_SUBDIR=	knu
DISTFILES=	rogue_s.tar.z rogue_s.patch02.z rogue_s.patch03.z \
		rogue_s.message.z
EXTRACT_ONLY=	rogue_s.tar.z

PATCH_SITES=	${MASTER_SITE_LOCAL} \
		${MASTER_SITE_PORTS_JP:S,/%SUBDIR%/,/,}
PATCH_SITE_SUBDIR=	knu
PATCHFILES=	rogue_s.patch04

MAINTAINER=	mistral@imasy.or.jp
COMMENT=	Japanized and message separated version of Rogue-clone: Version II

BUILD_DEPENDS=  nkf:${PORTSDIR}/japanese/nkf

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	Makefile.nix
ALL_TARGET=	rogue

MAN6=		rogue_s.6
MANLANG=	ja
MANCOMPRESSED=	no

DOC_DIR=	${PREFIX}/share/doc/rogue
DOCS=		README README.1st README.doc options.doc rogue.doc
MESG_DIR=	${PREFIX}/share/rogue

pre-patch:
	@(\
	  cd ${WRKSRC} ; \
	  ${GZCAT} ${DISTDIR}/rogue_s.patch02.z | uudecode -p | ${PATCH} --quiet ;\
	  ${GZCAT} ${DISTDIR}/rogue_s.patch03.z | ${PATCH} --quiet \
	)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rogue ${PREFIX}/bin/rogue_s
	${SED} "s#PREFIX#${PREFIX}#" ${FILESDIR}/rogue_s.6 > ${WRKSRC}/rogue_s.6
	${INSTALL_MAN} ${WRKSRC}/rogue_s.6 ${PREFIX}/man/ja/man6/rogue_s.6
	${MKDIR} ${MESG_DIR}
	${INSTALL_DATA} ${WRKSRC}/mesg ${MESG_DIR}
	${INSTALL_DATA} ${WRKSRC}/mesg_E ${MESG_DIR}
	${GZCAT} ${FILESDIR}/mesg_fj.gz > ${WRKDIR}/mesg_fj
	${INSTALL_DATA} ${WRKDIR}/mesg_fj ${MESG_DIR}/mesg_fj
	@(\
	  cd ${WRKDIR} ; \
	  ${GZCAT} ${DISTDIR}/rogue_s.message.z | \
		${AWK} '{if (/^\#/) x++} {if(x) print $$0}' | ${SH} \
	)
	nkf -e ${WRKDIR}/mesg_utmc > ${WRKDIR}/mesg_utmc.euc
	${INSTALL_DATA} ${WRKDIR}/mesg_utmc.euc ${MESG_DIR}/mesg_utmc

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOC_DIR}
	for file in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/"$$file" ${DOC_DIR} ; \
	done
.endif

.include <bsd.port.mk>

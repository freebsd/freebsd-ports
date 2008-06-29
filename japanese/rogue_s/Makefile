# New ports collection makefile for:   rogue_s
# Date created:		3 December 1998
# Whom:			Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	rogue_s
PORTVERSION=	1.3a
PORTREVISION=	2
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

.if !defined(NOPORTDATA)
BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	Makefile.nix
ALL_TARGET=	rogue
MAKE_ENV+=	DATADIR="${DATADIR}"

SUB_FILES=	rogue_s.6
MAN6=		rogue_s.6
MANLANG=	ja
MANCOMPRESSED=	no

PLIST_FILES=	bin/rogue_s
PORTDATA=	mesg mesg_E mesg_fj mesg_utmc
PORTDOCS=	README README.1st README.doc options.doc rogue.doc

pre-patch:
	@(\
	  cd ${WRKSRC} ; \
	  ${GZCAT} ${DISTDIR}/rogue_s.patch02.z | uudecode -p | ${PATCH} --quiet ;\
	  ${GZCAT} ${DISTDIR}/rogue_s.patch03.z | ${PATCH} --quiet \
	)

post-build:
.if !defined(NOPORTDATA)
	${GZCAT} ${FILESDIR}/mesg_fj.gz > ${WRKDIR}/mesg_fj
	@(\
	  cd ${WRKDIR} ; \
	  ${GZCAT} ${DISTDIR}/rogue_s.message.z | \
		${AWK} '{if (/^\#/) x++} {if(x) print $$0}' | ${SH} \
	)
	nkf -e ${WRKDIR}/mesg_utmc > ${WRKDIR}/mesg_utmc.euc
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rogue ${PREFIX}/bin/rogue_s
	${INSTALL_MAN} ${WRKDIR}/rogue_s.6 ${MAN6PREFIX}/man/ja/man6/rogue_s.6

.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mesg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mesg_E ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/mesg_fj ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/mesg_utmc.euc ${DATADIR}/mesg_utmc
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for _file in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/"$$_file" ${DOCSDIR} ; \
	done
.endif

.include <bsd.port.mk>

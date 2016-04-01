# Created by: Yoshihiko Sarumaru <mistral@imasy.or.jp>
# $FreeBSD$

PORTNAME=	rogue_s
PORTVERSION=	1.3a
PORTREVISION=	2
CATEGORIES=	japanese games
MASTER_SITES=	LOCAL/knu PORTS_JP
DISTFILES=	rogue_s.tar.z rogue_s.patch02.z rogue_s.patch03.z \
		rogue_s.message.z
EXTRACT_ONLY=	rogue_s.tar.z

PATCH_SITES=	LOCAL/knu PORTS_JP
PATCHFILES=	rogue_s.patch04

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanized and message separated version of Rogue-clone: Version II

BUILD_DEPENDS=	nkf:japanese/nkf

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	Makefile.nix
ALL_TARGET=	rogue
MAKE_ENV+=	DATADIR="${DATADIR}"

SUB_FILES=	rogue_s.6

PLIST_FILES=	bin/rogue_s man/ja/man6/rogue_s.6.gz
PORTDATA=	mesg mesg_E mesg_fj mesg_utmc
PORTDOCS=	README README.1st README.doc options.doc rogue.doc

OPTIONS_DEFINE=	DOCS

pre-patch:
	@(\
	  cd ${WRKSRC} ; \
	  ${GZCAT} ${DISTDIR}/rogue_s.patch02.z | uudecode -p | ${PATCH} --quiet ;\
	  ${GZCAT} ${DISTDIR}/rogue_s.patch03.z | ${PATCH} --quiet \
	)

post-build:
	${GZCAT} ${FILESDIR}/mesg_fj.gz > ${WRKDIR}/mesg_fj
	@(\
	  cd ${WRKDIR} ; \
	  ${GZCAT} ${DISTDIR}/rogue_s.message.z | \
		${AWK} '{if (/^\#/) x++} {if(x) print $$0}' | ${SH} \
	)
	nkf -e ${WRKDIR}/mesg_utmc > ${WRKDIR}/mesg_utmc.euc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rogue ${STAGEDIR}${PREFIX}/bin/rogue_s
	${INSTALL_MAN} ${WRKDIR}/rogue_s.6 ${STAGEDIR}${MANPREFIX}/man/ja/man6/rogue_s.6
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mesg ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mesg_E ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/mesg_fj ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/mesg_utmc.euc ${STAGEDIR}${DATADIR}/mesg_utmc
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	for _file in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/"$$_file" ${STAGEDIR}${DOCSDIR} ; \
	done

.include <bsd.port.mk>

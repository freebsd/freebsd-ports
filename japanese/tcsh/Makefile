# New ports collection makefile for:	tcsh with kanji patch
# Version required:	6.07.09
# Date created:		29 November 1997
# Whom:			issei <issei@jp.FreeBSD.ORG>
#
# $Id: Makefile,v 1.4 1998/07/04 03:20:11 steve Exp $
#

DISTNAME=	tcsh-6.07.09
PKGNAME=	ja-tcsh-6.07.09b5
CATEGORIES=	japanese shells
MASTER_SITES=	http://www2.wbs.ne.jp/~znc/tcsh/
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://www2.wbs.ne.jp/~znc/tcsh/
PATCHFILES=	${DISTNAME}.kanji.patch7b5.gz

MAINTAINER=	issei@jp.FreeBSD.ORG

PATCH_DIST_STRIP=       -p1
GNU_CONFIGURE=	yes
# Ugly hack
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin
ALL_TARGET=	all catalogs
INSTALL_TARGET=	install install.man
MAN1= 		tcsh.1
PORTDOCS=	complete.tcsh FAQ HISTORY.kanji.patch.euc HowToMakeNLS.euc \
		README.kanji.patch.euc

post-install:
	@(cd ${WRKSRC}; \
	${INSTALL_DATA} tcsh.C.cat ${PREFIX}/share/nls/C/tcsh.cat; \
	${INSTALL_DATA} tcsh.C.m ${PREFIX}/share/nls/C/tcsh.m; \
	)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tcsh
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/tcsh/
.endfor
.endif
	@${ECHO} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/tcsh /etc/shells.bak; ${ECHO} ${PREFIX}/bin/tcsh) >/etc/shells
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>

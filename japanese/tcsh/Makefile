# New ports collection makefile for:	tcsh with color-ls and kanji patches
# Version required:	6.07.02
# Date created:		29 November 1997
# Whom:			issei <issei@t-cnet.or.jp>
#
# $Id: Makefile,v 1.2 1997/12/27 19:35:58 max Exp $
#

DISTNAME=	tcsh-6.07
PKGNAME=	ja-tcsh-6.07.02
CATEGORIES=	japanese shells
MASTER_SITES=	ftp://ftp.jp.freebsd.org/pub/FreeBSD/distfiles/ \
		ftp://ftp.iis.u-tokyo.ac.jp/pub7/FreeBSD/distfiles/ \
		ftp://ftp.chem.sci.osaka-u.ac.jp/pub/unix/tools/tcsh/

PATCH_SITES=	http://www2.wbs.or.jp/~znc/tcsh/ \
		ftp://ftp.ccs.dendai.ac.jp/pub/misc/shell/tcsh/ \
		http://www.is.s.u-tokyo.ac.jp/~nayuta/pub/ \
		ftp://ftp.lab.kdd.co.jp/Usenet/fj.sources/1996/dec/
PATCHFILES=	tcsh-6.07.02.kanji.patch6a.gz tcsh-6.07.02-color-1.04.patch.gz
PATCH_DIST_STRIP=       -p1

MAINTAINER=	issei@t-cnet.or.jp

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/tcsh-6.07.02
ALL_TARGET=	all catalogs
INSTALL_TARGET=	install install.man
MAN1= 		tcsh.1

post-install:
	@(cd ${WRKSRC}; \
	${INSTALL_DATA} tcsh.C.cat ${PREFIX}/share/nls/C/tcsh.cat; \
	${INSTALL_DATA} tcsh.C.m ${PREFIX}/share/nls/C/tcsh.m; \
	${INSTALL_DATA} tcsh.ja.cat ${PREFIX}/share/nls/ja_JP.EUC/tcsh.cat; \
	${INSTALL_DATA} tcsh.ja.m ${PREFIX}/share/nls/ja_JP.EUC/tcsh.m; \
	)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tcsh
	@${INSTALL_DATA} ${WRKSRC}/README-color.jp ${PREFIX}/share/doc/tcsh/
	@${INSTALL_DATA} ${WRKSRC}/README.kanji.patch.euc ${PREFIX}/share/doc/tcsh/
.endif
	@${ECHO} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(grep -v ${PREFIX}/bin/tcsh /etc/shells.bak; ${ECHO} ${PREFIX}/bin/tcsh) >/etc/shells

.include <bsd.port.mk>

# New ports collection makefile for:	weblint97
# Version required:	0.12
# Date created:		27 Jun 1997
# Whom:			Takayuki Ariga <a00821@cc.hc.keio.ac.jp>
#
# $Id: Makefile,v 1.2 1997/09/14 21:36:22 max Exp $
#

DISTNAME=	weblint-97-0.12
PKGNAME=	ja-weblint97-0.12
CATEGORIES=	japanese www
MASTER_SITES=	ftp://ftp.win.or.jp/pub/network/www/weblint/ \
		ftp://ftp.sra.co.jp/pub/cmd/ \
		ftp://ftp.hipecs.hokudai.ac.jp/pub/network/WWW/contrib/

MAINTAINER=	a00821@cc.hc.keio.ac.jp

WRKSRC=         ${WRKDIR}/weblint-97
MANLANG=	ja
MAN1=		jweblint.1
MAKE_ENV+=      PERLLIBDIR="${PERLLIBDIR}"
ALL_TARGET=	euc-jp
INSTALL_TARGET=	jinstall

PORTDOCDIR?=	${PREFIX}/share/doc/jweblint
PERLLIBDIR?=	${PREFIX}/lib/perl

pre-install:
	@${SED} -e "s,%PERLLIBDIR%,${PERLLIBDIR},g" < ${WRKSRC}/jweblint.tmp \
		> ${WRKSRC}/jweblint
.if !exists(${PERLLIBDIR})
	@${MKDIR} ${PERLLIBDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PORTDOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/l10n/ja-jp/jmanpage.html ${PORTDOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/l10n/ja-jp/warnings.html ${PORTDOCDIR}
.endif

.include <bsd.port.mk>

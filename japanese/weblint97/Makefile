# New ports collection makefile for:	weblint97
# Date created:		27 Jun 1997
# Whom:			Takayuki Ariga <a00821@cc.hc.keio.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	weblint97
PORTVERSION=	0.12
CATEGORIES=	japanese www
MASTER_SITES=	http://www.sfc.keio.ac.jp/~mimasa/jweblint/ \
		ftp://ftp.win.ne.jp/pub/network/www/weblint/ \
		ftp://ftp.hipecs.hokudai.ac.jp/pub/network/WWW/contrib/
DISTNAME=	weblint-97-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An internationalized HTML checker with japanese message(EUC-JP)

RUN_DEPENDS=	${SITE_PERL}/jcode.pl:${PORTSDIR}/japanese/jcode.pl

BROKEN=		"Incomplete pkg-plist (port installs into nonstandard perl directory)"
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=2005-09-22

WRKSRC=		${WRKDIR}/weblint-97
MANLANG=	ja
MAN1=		jweblint.1
MAKE_ENV=	PERLLIBDIR="${PERLLIBDIR}"
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

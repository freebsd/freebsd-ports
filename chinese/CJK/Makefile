# New ports collection makefile for:	zh-CJK
# Date created:		5 Sep 1999
# Whom:			Jing-Tang Keith Jang (keith@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	CJK
PORTVERSION=	4.5.2
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/cjk/\
  		ftp://ftp.ffii.org/pub/cjk/
DISTNAME=	cjk-${PORTVERSION}

MAINTAINER=	rafan@infor.org
COMMENT=	A LaTeX2e macro package which enables the use of CJK scripts

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		${LOCALBASE}/share/fonts/TrueType/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf \
		ttf2pk:${PORTSDIR}/print/freetype-tools
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_GMAKE=	yes
USE_FREETYPE=	yes
ARPHICDIR=	${PREFIX}/share/texmf/fonts/truetype/arphic

MAN1=		bg5conv.1 cef5conv.1 cefconv.1 cefsconv.1 extconv.1 \
		hbf2gf.1 sjisconv.1

pre-patch:
	@${RM} -f ${WRKSRC}/Makefile

post-patch:
	@${RM} -f ${WRKSRC}/texinput/Bg5/c00bsmi.fd.orig

post-install:
.if !defined(NOPORTDOCS)
	${RM} -fr ${PREFIX}/share/doc/CJK
	${CP} -R ${WRKSRC}/doc ${PREFIX}/share/doc/CJK
.endif
	${RM} -fr ${PREFIX}/share/examples/CJK
	${CP} -R ${WRKSRC}/examples ${PREFIX}/share/examples/CJK
	@${MKDIR} ${ARPHICDIR}	# Install Arphic fonts
	@${LN} -fs ${PREFIX}/share/fonts/TrueType/bkai00mp.ttf ${ARPHICDIR}/arb5_kai.ttf
	@${LN} -fs ${PREFIX}/share/fonts/TrueType/bsmi00lp.ttf ${ARPHICDIR}/arb5_sung.ttf
	@${LN} -fs ${PREFIX}/share/fonts/TrueType/gbsn00lp.ttf ${ARPHICDIR}/argb_sung.ttf
	@${LN} -fs ${PREFIX}/share/fonts/TrueType/gkai00mp.ttf ${ARPHICDIR}/argb_kai.ttf

.include <bsd.port.mk>

# New ports collection makefile for:	zh-CJK
# Version required:	4.2.0
# Date created:		1 March 1999
# Whom:			J.T. Jang (jtjang@gcn.net.tw)
#
# $FreeBSD$
#

DISTNAME=	zh-CJK-4.2.0
CATEGORIES=	chinese
# Only the first three sites in MASTER_SITE_TEX_CTAN support compressing
# on-the-fly. Then try my homepage. Go to CTAN if all fails.
MASTER_SITES=	ftp://ftp.funet.fi/pub/TeX/CTAN/language/chinese/ \
		ftp://ftp.tex.ac.uk/tex-archive/language/chinese/ \
		ftp://ftp.dante.de/tex-archive/language/chinese/ \
		http://member.gcn.net.tw/web/jtjang/ \
		ftp://ftp.ctan.org/tex-archive/language/chinese/
MASTER_SITE_SUBDIR=	language/chinese
DISTFILES=	CJK.tar.gz

MAINTAINER=	jtjang@gcn.net.tw

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	ttf.3:${PORTSDIR}/print/freetype
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

IGNOREFILES=	CJK.tar.gz
NO_PACKAGE=	Interactive

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/CJK/4_2.0

.if !defined $(NOTTF)
MASTER_SITES+=	ftp://linux.cis.nctu.edu.tw/packages/chinese/fonts/twmoefont/ttf/ \
		ftp://axp350.ncu.edu.tw/OS/Linux/Chinese/fonts/twmoefont/ttf/ \
		ftp://ftp.nsysu.edu.tw/Linux/packages/chinese/fonts/twmoefont/ttf/
DISTFILES+=	moe_kai.ttf moe_sung.ttf
EXTRACT_ONLY=	CJK.tar.gz
.endif

post-install:
.if !defined(NOPORTDOCS)
	${CP} -R ${WRKSRC}/doc ${PREFIX}/share/doc/CJK
	${CP} -R ${WRKSRC}/examples ${PREFIX}/share/examples/CJK
.endif

MAN1=		bg5conv.1 cef5conv.1 cefconv.1 cefsconv.1 hbf2gf.1 \
		sjisconv.1 thaiconv.1 ttf2pk.1 ttf2tfm.1

.include <bsd.port.mk>

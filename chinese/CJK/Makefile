# New ports collection makefile for:	zh-CJK
# Version required:	4.1.3
# Date created:		17 June 1998
# Whom:			J.T. Jang (keith@email.gcn.net.tw)
#
# $Id: Makefile,v 1.2 1998/10/10 13:39:00 vanilla Exp $
#

DISTNAME=	CJK-4.1.3.src
PKGNAME=	zh-CJK-4.1.3
CATEGORIES=	chinese
MASTER_SITES=	ftp://ftp.edu.tw/Chinese/ifcss/software/tex/ \
		ftp://ntcuccca.edu.tw/Chinese/ifcss/software/tex/ \
		ftp://ftp.ifcss.org/pub/software/tex/

MAINTAINER=	keith@email.gcn.net.tw

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

BROKEN=		patching during install

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/CJK

.if defined $(USE_NTUTTF)
MASTER_SITES+=	ftp://ftp.edu.tw/Chinese/ifcss/software/fonts/big5/ms-win/ \
		ftp://ntcuccca.edu.tw/Chinese/ifcss/software/fonts/big5/ms-win/ \
		ftp://ftp.ifcss.org/pub/software/software/fonts/big5/ms-win/
DISTFILES+=	ntu_kai.a01 ntu_kai.a02 ntu_kai.a03 ntu_kai.arj
BUILD_DEPENDS+=	unarj:${PORTSDIR}/archivers/unarj
EXTRACT_ONLY=	CJK-4.1.3.src.tar.gz
.endif

pre-fetch:
	@echo
	@echo You can use \"$(MAKE) USE_NTUTTF=YES\" to install
	@echo NTU truetype fonts, aka. ntu_kai.ttf as default.
	@echo

pre-install:
	@echo
	@echo You can use \"$(MAKE) test-teTeX-patch\" to test whether
	@echo this patch actually applies cleanly on your teTeX system.
	@echo "(It doesn't modify any existing files.)"
	@echo

post-install:
	@${SETENV} PREFIX=${PREFIX} ${SH} ${FILESDIR}/install-note

test-teTeX-patch: patch
	(cd $(WRKSRC); $(GMAKE) test-teTeX-patch)

MAN1=		hbf2gf.1 bg5conv.1 ttf2pk.1

.include <bsd.port.mk>

# New ports collection makefile for:	skkinput
# Version required:	2.00
# Date created:		28 Jan 1998
# Whom:			Murata Shuuichirou <mrt@mickey.ai.kyutech.ac.jp>
#
# $Id: Makefile,v 1.4 1998/04/18 15:50:18 kuriyama Exp $
#

DISTNAME=	skkinput-2.00
PKGNAME=	ja-skkinput-2.00
CATEGORIES=	japanese x11
MASTER_SITES=	http://www.yajima.kuis.kyoto-u.ac.jp/staffs/sakamoto/skkinput/

MAINTAINER=	mrt@mickey.ai.kyutech.ac.jp

RUN_DEPENDS=	${LOCALBASE}/libexec/skkserv:${PORTSDIR}/japanese/skk \
		jman:${PORTSDIR}/japanese/man

USE_IMAKE=	yes
MANLANG=	ja
MAN1=		skkinput.1
MANCOMPRESSED=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${X11BASE}/share/doc/skkinput
	@( cd ${WRKSRC} ; \
	   ${INSTALL_DATA} *.jis skkinput.doc ${X11BASE}/share/doc/skkinput/ )
.endif

.include <bsd.port.mk>

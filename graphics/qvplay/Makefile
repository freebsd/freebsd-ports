# New ports collection makefile for:	qvplay
# Version required:	0.92
# Date created:		2 May 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.1.1.1 1997/05/20 06:19:51 asami Exp $
#

DISTNAME=	qvplay-0.92
CATEGORIES=	graphics
MASTER_SITES=   http://www.asahi-net.or.jp/~xg2k-hys/

MAINTAINER=	itojun@itojun.org

RESTRICTED=	"Redistribution prohibited since it is in beta test period"

WRKSRC=		${WRKDIR}/QVplay092/obj/FreeBSD
GNU_CONFIGURE=	yes

DOC=	README README.eng README.FreeBSD FAQ.txt HISTORY PROTOCOL.txt \
	PROTOCOL.eng

pre-configure:
	@( cd ${WRKDIR}/QVplay092; ./setup FreeBSD )

post-install:
	${MKDIR} ${PREFIX}/share/doc/qvplay
	for i in ${DOC}; do \
		${INSTALL_DATA} ${WRKSRC}/../../$$i \
			${PREFIX}/share/doc/qvplay; \
	done
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>

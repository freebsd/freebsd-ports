# New ports collection makefile for:	qvplay
# Version required:	0.94
# Date created:		2 May 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

DISTNAME=	qvplay-0.94
CATEGORIES=	graphics
MASTER_SITES=   http://www.asahi-net.or.jp/~xg2k-hys/

MAINTAINER=	itojun@itojun.org

RESTRICTED=	"Redistribution prohibited since it is in beta test period"

WRKSRC=		${WRKDIR}/QVplay094/obj/FreeBSD
GNU_CONFIGURE=	yes
MAN1= 		qvplay.1 qvrec.1 qvalldel.1
MAKE_ARGS+=	INSTALL_MAN="${INSTALL_MAN}"

DOC=	README README.eng README.FreeBSD FAQ.txt HISTORY PROTOCOL.txt \
	PROTOCOL.eng

pre-patch:
	@${MKDIR} ${WRKSRC}

pre-configure:
	@( cd ${WRKDIR}/QVplay094; ./setup FreeBSD )

post-install:
	@${MKDIR} ${PREFIX}/share/doc/qvplay
	for i in ${DOC}; do \
		${INSTALL_DATA} ${WRKSRC}/../../$$i \
			${PREFIX}/share/doc/qvplay; \
	done
	@${ECHO} && ${ECHO}
	@${SED} -e 's#/usr/local#${PREFIX}#' ${PKGDIR}/MESSAGE

.include <bsd.port.mk>

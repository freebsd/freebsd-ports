# New ports collection makefile for:	qvplay
# Date created:		2 May 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	qvplay
PORTVERSION=	0.95
CATEGORIES=	graphics
MASTER_SITES=	http://www.asahi-net.or.jp/~xg2k-hys/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/QVplay095/obj/FreeBSD

GNU_CONFIGURE=	yes

MAN1= 		qvplay.1 qvrec.1 qvalldel.1

PORTDOCS=	FAQ.txt HISTORY PROTOCOL.txt PROTOCOL.eng \
		README README.eng README.FreeBSD

pre-patch:
	@${MKDIR} ${WRKSRC}

pre-configure:
	@( cd ${WRKDIR}/QVplay095; ./setup FreeBSD )

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/qvplay
.for file  in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/../../${file} ${PREFIX}/share/doc/qvplay
.endfor
.endif
	@${SED} -e 's#/usr/local#${PREFIX}#' ${PKGMESSAGE}

.include <bsd.port.mk>

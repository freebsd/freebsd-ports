# New ports collection makefile for:	pathchirp
# Date created:			19 May 2005
# Whom:				dikshie <dikshie@lapi.itb.ac.id>
#
# $FreeBSD$
#

PORTNAME=	pathchirp
PORTVERSION=	2.4.1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.spin.rice.edu/Software/pathChirp/

MAINTAINER=	dikshie@lapi.itb.ac.id
COMMENT=	A measurement tool for available bandwidth estimation

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/pathchirp_rcv bin/pathchirp_snd bin/pathchirp_run
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e '/CFLAGS.*O4/d' ${WRKSRC}/configure

do-install:
.for f in rcv snd run
	${INSTALL_PROGRAM} ${WRKSRC}/Bin/${ARCH}/${PORTNAME}_${f} ${PREFIX}/bin
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

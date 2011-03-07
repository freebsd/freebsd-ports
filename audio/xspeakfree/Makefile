# New ports collection makefile for:	xspeakfree
# Date created:			08 Nov 2003
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	xspeakfree
PORTVERSION=	0.8.2
PORTREVISION=	3
CATEGORIES=	audio tk mbone
MASTER_SITES=	http://www.liquidx.org/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/Tk (wish) frontend to Speak Freely

DEPRECATED=	Unmaintained, unfetchable, mail freebsd-ports@FreeBSD.org if interested
EXPIRATION=	2011-06-30

RUN_DEPENDS=	${LOCALBASE}/bin/wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		${LOCALBASE}/bin/sfmike:${PORTSDIR}/audio/speak_freely

NO_BUILD=	yes

.ifndef NOPORTDOCS
PORTDOCS=	BUGS HISTORY INSTALL LICENSE README TODO
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|wish|wish8.4|' ${WRKSRC}/bin/xspeakfree

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/xspeakfree ${PREFIX}/bin/xspeakfree
	${MKDIR} ${PREFIX}/lib/xspeakfree
	${INSTALL_DATA} ${WRKSRC}/lib/xspeakfree/* ${PREFIX}/lib/xspeakfree
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

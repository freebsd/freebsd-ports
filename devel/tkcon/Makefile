# New ports collection makefile for:	tkcon
# Date created:         28 Jun 1999
# Whom:                 wghicks@bellsouth.net
#
# $FreeBSD$
#

PORTNAME=	tkcon
PORTVERSION=	2.4
CATEGORIES=	devel tcl84 tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tk console for Tcl

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

USE_REINPLACE=	yes
NO_BUILD=	yes
REINPLACE_ARGS=	-i.bak -E

post-patch:
	@${REINPLACE_CMD} \
		-e 's,docs\s+"([^"]+)",docs	"file:${PREFIX}/share/doc/tkcon/index.html\\n\1",' ${WRKSRC}/tkcon.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkcon.tcl ${PREFIX}/bin/tkcon

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/tkcon
	${INSTALL_DATA} ${WRKSRC}/README.txt $(PREFIX)/share/doc/tkcon/README.tkcon
	${INSTALL_DATA} ${WRKSRC}/docs/* $(PREFIX)/share/doc/tkcon
.endif

.include <bsd.port.mk>

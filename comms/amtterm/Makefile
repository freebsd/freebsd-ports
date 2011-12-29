# Ports collection Makefile for:	amtterm
# Date created:				29 December 2011
# Whom:					crees
#
# $FreeBSD$
#

PORTNAME=	amtterm
PORTVERSION=	1.3
CATEGORIES=	comms
MASTER_SITES=	https://www.kraxel.org/releases/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Serial-over-lan client for Intel AMT

LIB_DEPENDS=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20
RUN_DEPENDS=	p5-SOAP-Lite>=0.5:${PORTSDIR}/net/p5-SOAP-Lite

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ENV+=	mandir=${MANPREFIX}/man

PLIST_FILES=	bin/${PORTNAME} \
		bin/amttool \
		share/applications/gamt.desktop
PLIST_DIRSTRY=	share/applications
MAN1=		gamt.1 ${PORTNAME}.1 amttool.1
MAN7=		amt-howto.7
MANCOMPRESSED=	no

post-patch:
	@${REINPLACE_CMD} -e 's,/sbin/ldconfig -p,${LDCONFIG} -r,' \
		${WRKSRC}/mk/Autoconf.mk
.for mandir in 1 7
	@${REINPLACE_CMD} -e \
	   's,$$(mandir)/man${mandir},${MAN${mandir}PREFIX}/man/man${mandir},' \
		${WRKSRC}/${MAKEFILE}
.endfor

.include <bsd.port.mk>

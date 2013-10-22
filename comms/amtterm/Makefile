# $FreeBSD$

PORTNAME=	amtterm
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	https://www.kraxel.org/releases/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Serial-over-lan client for Intel AMT

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-SOAP-Lite>=0.5:${PORTSDIR}/net/p5-SOAP-Lite

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ENV+=	mandir=${MANPREFIX}/man
MAKE_ARGS+=	HAVE_GTK=no

PLIST_FILES=	bin/${PORTNAME} \
		bin/amttool \
		share/applications/gamt.desktop
MAN1=		gamt.1 ${PORTNAME}.1 amttool.1
MAN7=		amt-howto.7
MANCOMPRESSED=	no

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,/sbin/ldconfig -p,${LDCONFIG} -r,' \
		${WRKSRC}/mk/Autoconf.mk
.for mandir in 1 7
	@${REINPLACE_CMD} -e \
	   's,$$(mandir)/man${mandir},${MAN${mandir}PREFIX}/man/man${mandir},' \
		${WRKSRC}/${MAKEFILE}
.endfor

.include <bsd.port.mk>

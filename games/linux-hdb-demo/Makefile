# New ports collection makefile for:	linux-hdb-demo
# Date created:		2009-02-01
# Whom:			Marcus von Appen <mva@sysfault.org>
#
# $FreeBSD$
#

PORTNAME=	hdb-demo
PORTVERSION=	1.0
CATEGORIES=	games linux
MASTER_SITES=	http://demofiles.linuxgamepublishing.com/hdb/
PKGNAMEPREFIX=	linux-
DISTNAME=	hdb_demo
EXTRACT_SUFX=	.run

MAINTAINER=	mva@sysfault.org
COMMENT=	Hyperspace Delivery Boy Demo - deliver mail and packages

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12 \
		${LINUXBASE}/usr/lib/libSDL_mixer-1.2.so.0:${PORTSDIR}/audio/linux-sdl_mixer \
		${LINUXBASE}/usr/lib/libmikmod.so.2:${PORTSDIR}/audio/linux-mikmod \
		${LINUXBASE}/usr/lib/libogg.so.0:${PORTSDIR}/audio/linux-libogg \
		${LINUXBASE}/usr/lib/libvorbis.so.0:${PORTSDIR}/audio/linux-libvorbis

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_XLIB=	yes
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	hdb
PORTDOCS=	README README.licenses README.unixthanks license.txt

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAIL} +377 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} jxf -

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/hdb_demo
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/hdb_demo.dynamic

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/bin/Linux/x86 && \
		${INSTALL_PROGRAM} hdb_demo hdb_demo.dynamic ${DATADIR}
	@${INSTALL_PROGRAM} ${WRKDIR}/hdb ${PREFIX}/bin/${PKGNAMEPREFIX}hdb
	@${CP} -R ${WRKSRC}/Resources ${DATADIR}
	@${CP} -R ${WRKSRC}/music ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/hyperdemo.mpc ${DATADIR}
.if !defined (NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

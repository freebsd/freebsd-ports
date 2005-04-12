# New ports collection makefile for:	updatedd
# Date created:		2003-12-02
# Whom:			geniusj@ods.org
#
# $FreeBSD$
#

PORTNAME=	updatedd
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}-1

MAINTAINER=	geniusj@ods.org
COMMENT=	Dynamic DNS Update Client supporting multiple services

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
LIBDIR=		${PREFIX}/lib/${PORTNAME}

MAN1=		updatedd.1
DOCS=		Documentation/README.* Documentation/rc_updatedd_*

# Default Service Plugin
# Valid services: dyndns, hn, noip, ods, ovh
DEFAULTPLUGIN?=	ods

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/updatedd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Documentation/*.1 ${MAN1PREFIX}/man/man1
	@${MKDIR} ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/src/plugins/*.so ${LIBDIR}
	${LN} -sf ${LIBDIR}/${DEFAULTPLUGIN}.so ${LIBDIR}/default.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

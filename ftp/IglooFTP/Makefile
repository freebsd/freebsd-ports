# New ports collection makefile for:	IglooFTP
# Date created:				3 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		IglooFTP
PORTVERSION=		0.6.1
CATEGORIES=		ftp
MASTER_SITES=		${MASTER_SITE_SUNSITE} \
			ftp://littleigloo.org/pub/iglooftp/
MASTER_SITE_SUBDIR=	system/network/file-transfer
DISTNAME=		${PORTNAME}-${PORTVERSION}.src

MAINTAINER=		will@FreeBSD.org

LIB_DEPENDS=		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=		${X11BASE}/bin/gtk12-config

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_X_PREFIX=		yes
MAKE_ENV=		GTK_CONFIG="${GTK_CONFIG}"
ALL_TARGET=		IglooFTP

post-extract:
	@${RM} ${WRKSRC}/../share/docs/LICENSE~

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/IglooFTP
.for file in AUTHORS BUGS COPYRIGHT THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/../${file} ${PREFIX}/share/doc/IglooFTP
.endfor
.endif

.include <bsd.port.mk>

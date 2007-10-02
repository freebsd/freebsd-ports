# New ports collection makefile for:	IglooFTP
# Date created:				3 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	IglooFTP
PORTVERSION=	0.6.1
PORTREVISION=	4
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://littleigloo.org/pub/iglooftp/
MASTER_SITE_SUBDIR=	system/network/file-transfer
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	Easy to use FTP client for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
ALL_TARGET=	# empty
MAKE_ARGS=	CC=${CC} C_FLAGS="${CFLAGS}" DESTDIR=${PREFIX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

post-extract:
	@${RM} ${WRKSRC}/../share/docs/LICENSE~

post-install:
.if !defined(NOPORTDOCS)
.for file in AUTHORS BUGS COPYRIGHT THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/../${file} ${PREFIX}/share/IglooFTP/docs
.endfor
.endif

.include <bsd.port.post.mk>

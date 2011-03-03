# New ports collection makefile for:	IglooFTP
# Date created:				3 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	IglooFTP
PORTVERSION=	0.6.1
PORTREVISION=	6
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://littleigloo.org/pub/iglooftp/
MASTER_SITE_SUBDIR=	system/network/file-transfer
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Easy to use FTP client for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_XORG=	x11 xmu
USE_GNOME=	gtk12
ALL_TARGET=	# empty
MAKE_ARGS=	CC=${CC} C_FLAGS="${CFLAGS}" DESTDIR=${PREFIX}
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

post-extract:
	@${RM} ${WRKSRC}/../share/docs/LICENSE~

post-patch:
	@${REINPLACE_CMD} -e 's|(char) user_rc.default_session.firewall_login_type|user_rc.default_session.firewall_login_type|' \
		${WRKSRC}/custom_io.h

post-install:
.if !defined(NOPORTDOCS)
.for file in AUTHORS BUGS COPYRIGHT THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/../${file} ${PREFIX}/share/IglooFTP/docs
.endfor
.endif

.include <bsd.port.post.mk>

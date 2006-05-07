# New ports collection makefile for:	kftpgrabber
# Date created:				Thu Aug 19 00:35:34 CEST 2004
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kftpgrabber
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	ftp kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Graphical FTP client for KDE

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool:15

OPTIONS=	QSA  "QSA scripting support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_QSA)
LIB_DEPENDS+=	qsa.1:${PORTSDIR}/devel/qsa
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>

# New ports collection makefile for:	kftpgrabber
# Date created:				Thu Aug 19 00:35:34 CEST 2004
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kftpgrabber
PORTVERSION=	0.5.0.b1
CATEGORIES=	ftp kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b1/-beta1/}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Graphical FTP client for KDE

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

OPTIONS=	HOWL "ZeroConf (Rendezvous) support" off \
		QSA  "QSA scripting support" off

.include <bsd.port.pre.mk>

.if defined(WITH_HOWL)
LIB_DEPENDS+=	howl:${PORTSDIR}/net/howl
.endif

.if defined(WITH_QSA)
LIB_DEPENDS+=	qsa.1:${PORTSDIR}/devel/qsa
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>

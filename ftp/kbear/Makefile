# New ports collection makefile for:	kbear
# Date created:			Wed May 29 18:10:01 PDT 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=		kbear
PORTVERSION=		3.0.a.1
PORTREVISION=	1
CATEGORIES=		ftp kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}-${PORTVERSION:S/.a.1/alpha1b/}-1.src

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		A graphical FTP client for KDE

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.a.1/alpha1b/}
INSTALLS_SHLIB=		yes
USE_KDELIBS_VER=	3
USE_REINPLACE=		yes
USE_BZIP2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		XML2POT=${TRUE} PO2XML=${TRUE}

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>

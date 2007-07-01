# New ports collection makefile for:	filezilla
# Date created:				2006-10-24
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	filezilla
DISTVERSION=	3.0.0-beta7
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	SF
DISTNAME=	FileZilla_${DISTVERSION}_src

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Fast FTP and SFTP client with a lot of features

LIB_DEPENDS=	gnutls.13:${PORTSDIR}/security/gnutls \
		idn.16:${PORTSDIR}/dns/libidn

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_WX=		2.8
WX_CONF_ARGS=	relative
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|dummy wxrc|&-gtk2-${WX_VERSION}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>

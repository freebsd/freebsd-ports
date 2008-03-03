# New ports collection makefile for:	filezilla
# Date created:				2006-10-24
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	filezilla
DISTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	SF
DISTNAME=	FileZilla_${DISTVERSION}_src

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Fast and reliable cross-platform FTP, FTPS and SFTP client

LIB_DEPENDS=	gnutls.26:${PORTSDIR}/security/gnutls \
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
	@${REINPLACE_CMD} -Ee 's|(dummy) wxrc|\1 ${WXRC_CMD:T}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000 && ${ARCH} == i386
BROKEN=	Does not compile
.endif

.include <bsd.port.post.mk>

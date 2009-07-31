# New ports collection makefile for:	gimp-help
# Date created:				28 May, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/gimp-help/Makefile,v 1.1 2006/07/18 13:04:28 ahze Exp $
#

PORTNAME=	gimp-help
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		http://gimp.mirrors.hoobly.com/%SUBDIR%/ \
		http://ftp.gwdg.de/pub/misc/grafik/gimp/%SUBDIR%/ \
		ftp://ftp.fh-heilbronn.de/mirrors/ftp.gimp.org/%SUBDIR%/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/ftp.gimp.org/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gimp/help/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GIMP user's manual

LIB_DEPENDS=	gimp-2.0:${PORTSDIR}/graphics/gimp-app
BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl
RUN_DEPENDS=	${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|mkdir_p = .*|mkdir_p = ${WRKSRC}/install-sh -c -d|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

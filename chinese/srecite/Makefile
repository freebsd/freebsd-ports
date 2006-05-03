# Ports collection makefile for:	srecite
# Date created:				28 Oct 2004
# Whom:					hamigua <hamigua@cuc.cn>
#
# $FreeBSD$
#

PORTNAME=	srecite
PORTVERSION=	0.6.2
PORTREVISION=	3
CATEGORIES=	chinese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		wordbooks-utf8.tar.gz
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		wordbooks-utf8.tar.gz

MAINTAINER=	liu_yinghong@yahoo.com.cn
COMMENT=	A tool for the Chinese people to study foreign language

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui

WORDBOOKS_PATH=	${PREFIX}/share/gnome/${PORTNAME}/wordbooks

post-install:
	cd ${WRKDIR}/wordbooks && ${INSTALL_DATA} * ${WORDBOOKS_PATH}
	${INSTALL_DATA} ${FILESDIR}/srecite.desktop ${PREFIX}/share/gnome/applications

.include <bsd.port.mk>

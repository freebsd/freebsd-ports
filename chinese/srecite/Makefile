# Created by: hamigua <hamigua@cuc.cn>
# $FreeBSD$

PORTNAME=	srecite
PORTVERSION=	0.6.2
PORTREVISION=	11
CATEGORIES=	chinese textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/SRecite-${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		wordbooks-utf8.tar.gz
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		wordbooks-utf8.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for the Chinese people to study foreign language

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
USE_GMAKE=	yes
USES=        pathfix
USE_GNOME=	gnomeprefix libgnomeui

WORDBOOKS_PATH=	${PREFIX}/share/${PORTNAME}/wordbooks

NO_STAGE=	yes
post-install:
	cd ${WRKDIR}/wordbooks && ${INSTALL_DATA} * ${WORDBOOKS_PATH}
	${INSTALL_DATA} ${FILESDIR}/srecite.desktop ${PREFIX}/share/applications

.include <bsd.port.mk>

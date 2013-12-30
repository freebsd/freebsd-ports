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
COMMENT=	Tool for the Chinese people to study foreign language

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
USES=		gmake pathfix
USE_GNOME=	gnomeprefix libgnomeui

WORDBOOKS_PATH=	${PREFIX}/share/${PORTNAME}/wordbooks

post-install:
	${INSTALL_DATA} ${WRKDIR}/wordbooks/* ${STAGEDIR}${WORDBOOKS_PATH}
	${INSTALL_DATA} ${FILESDIR}/srecite.desktop ${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>

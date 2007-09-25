# New ports collection makefile for:	blender-doc
# Date created:		09-10-2007
# Whom:			Alex Ivasyuv <siegerstein@pochta.ru>
#
# $FreeBSD$
#

PORTNAME=	blender
PORTVERSION=	2.3
CATEGORIES=	graphics
MASTER_SITES=	http://download.blender.org/documentation/ \
			CENKES
PKGNAMESUFFIX=	-doc
DISTFILES=	BlenderManualIen.23.html.tar.gz BlenderManualIIen.23.html.tar.gz

MAINTAINER=	siegerstein@pochta.ru
COMMENT=	Blender Documentation

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

post-extract:
	@${CHMOD} u+rwx ${WRKSRC}/* && ${CHMOD} u+rwx ${WRKSRC}/*/* && \
		${CHMOD} u+rwx ${WRKSRC}/*/*/* && ${CHMOD} u+rwx ${WRKSRC}/*/*/*/*
	@cd ${WRKSRC}/htmlI/PartAT/volumetrics/gfx/ && \
		${RM} -rf  "Nuova cartella" "Nuova cartella (2)"

do-install:
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} "htmlI htmlII" ${DOCSDIR}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

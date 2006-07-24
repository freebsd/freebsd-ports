# New ports collection makefile for:	fpc-gconf
# Date created: 			2006-06-22
# Whom: 				Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	devel lang
PKGNAMESUFFIX=	-gconf

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to GConf

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils \
		${UNITSDIR}/gtk/Package.fpc:${PORTSDIR}/x11-toolkits/fpc-gtk \
		${UNITSDIR}/x11/Package.fpc:${PORTSDIR}/x11/fpc-x11 \
		${UNITSDIR}/opengl/Package.fpc:${PORTSDIR}/graphics/fpc-opengl

USE_GNOME=	gconf

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/extra/gnome1/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}
HAVE_EXAMPLES=	true

.include "${MASTERDIR}/Makefile"

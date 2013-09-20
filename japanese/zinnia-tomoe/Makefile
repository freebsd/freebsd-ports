# $FreeBSD$

# Date created:				15 Aug 2010
# Whom:					Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$
#

PORTNAME=	zinnia
PORTVERSION=	0.6.0
CATEGORIES=	japanese
MASTER_SITES=	SF/zinnia/${PORTNAME}${PKGNAMESUFFIX}/${PORTVERSION}-20080911
PKGNAMESUFFIX=	-tomoe
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}-20080911

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Handwriting Recognition files for Zinnia (Tomoe Data)

LIB_DEPENDS=	zinnia.0:${PORTSDIR}/japanese/zinnia
RUN_DEPENDS=	zinnia:${PORTSDIR}/japanese/zinnia

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
GMAKE=	yes
GNU_CONFIGURE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>

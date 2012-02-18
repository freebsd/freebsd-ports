# New ports collection makefile for:	opennurbs
# Date created:                		Aug 17 2011
# Whom:                        		Fernando Apesteguia <fernando.apesteguia@gmail.com>
#
# $FreeBSD$

PORTNAME=	opennurbs
PORTVERSION=	20111122
CATEGORIES=	graphics
MASTER_SITES=	http://files.na.mcneel.com/opennurbs/5.0/2011-11-22/
MASTER_SITE_SUBDIR=${PORTNAME}_${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Tools to accurately transfer 3-D geometry between applications

USE_DOS2UNIX=	yes
USE_GMAKE=	yes
USE_ZIP=	yes
USE_ICONV=	build

MAKEFILE=	makefile
EXAMPLESDIR=	${PREFIX}/libexec/openNURBS

pre-build:
	iconv -c -f utf-8 -t ascii ${WRKSRC}/opennurbs_version.h > ${WRKSRC}/opennurbs_version.h.tmp || ${TRUE}
	@${MV} ${WRKSRC}/opennurbs_version.h.tmp ${WRKSRC}/opennurbs_version.h

do-install:
	@${INSTALL_LIB} ${WRKSRC}/libopenNURBS.a ${PREFIX}/lib
	@${MKDIR} ${EXAMPLESDIR}
.for i in brep dump read roundtrip userdata write
	@${INSTALL_PROGRAM} ${WRKSRC}/example_${i}/example_${i} ${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>

# Created by: Andreas Daehn <ad001@uni-rostock.de>
# $FreeBSD$

PORTNAME=	jave6
PORTVERSION=	0.1
PORTREVISION=	5
CATEGORIES=	graphics java
MASTER_SITES=	http://www.jave.de/developer/\
		http://ikaria.informatik.uni-rostock.de/public_bsd/FreeBSD/
DISTNAME=	jave_6.0_i20060105

MAINTAINER=	ad001@uni-rostock.de
COMMENT=	Java ASCII-Art-Generator

EXTRACT_AFTER_ARGS=	-d ${WRKDIR}/${DISTNAME}

USES=		zip
USE_JAVA=	yes
NO_BUILD=	yes

SUB_FILES=	jave6 pkg-message
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

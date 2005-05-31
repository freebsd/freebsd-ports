# New ports collection makefile for:	phpeclipse
# Date created:				22 Oct 2003
# Whom:					rtdean@cytherianage.net
#
# $FreeBSD$
#

PORTNAME=	phpeclipse
PORTVERSION=	1.1.3
CATEGORIES=	java editors devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpeclipse
DISTNAME=	PHPEclipse${PORTVERSION}-2005-01-29

MAINTAINER=	rtdean@cytherianage.net
COMMENT=	PHP Eclipse adds PHP support to the Eclipse IDE Framework

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes

ECLIPSE=	${PREFIX}/eclipse

PLIST_SUB=	VER=${PORTVERSION} NSP=net.sourceforge.phpeclipse	\
		NSEVER=net.sf.eclipsetidy_1.2.1

do-install:
	@${CP} -r ${WRKSRC}/features/* ${ECLIPSE}/features
	@${CP} -r ${WRKSRC}/plugins/* ${ECLIPSE}/plugins

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

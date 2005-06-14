# New ports collection makefile for:	phpeclipse
# Date created:				22 Oct 2003
# Whom:					rtdean@cytherianage.net
#
# $FreeBSD$
#

PORTNAME=	phpeclipse
PORTVERSION=	1.1.4
CATEGORIES=	java editors devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	PHPeclipse-${PORTVERSION}-features

MAINTAINER=	rtdean@cytherianage.net
COMMENT=	PHP Eclipse adds PHP support to the Eclipse IDE Framework

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes

ECLIPSE=	${PREFIX}/eclipse

PLIST_SUB=	VER=${PORTVERSION} NSP=net.sourceforge.phpeclipse \
		QVER=com.quantum.Quantum_2.4.5 TEAMVER=3.0.0 \
		OTS=org.tigris.subversion OTSVER=0.9.30 UIVER=1.1.2 \
		TIDYVER=1.2.1 HTMLVER=1.1.3 UNITVER=phpunit_1.0.0

do-install:
	@${MKDIR} ${ECLIPSE}/features
	@${MKDIR} ${ECLIPSE}/plugins
	@${CP} -r ${WRKSRC}/eclipse/features/* ${ECLIPSE}/features
	@${CP} -r ${WRKSRC}/eclipse/plugins/* ${ECLIPSE}/plugins

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

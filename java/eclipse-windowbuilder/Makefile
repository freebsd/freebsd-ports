# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	windowsbuilder
PORTVERSION=	1.1.0
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/windowbuilder/WB/release/,} \
		${MASTER_SITE_LOCAL:S,%SUBDIR%/,ale/:native,}
MASTER_SITE_SUBDIR=	R201109201200
PKGNAMEPREFIX=	eclipse-
DISTFILES=	WB_v${PORTVERSION}_UpdateSite_for_Eclipse3.7.zip \
		org.eclipse.wb.os.freebsd_1.1.0.r37x201109091012.jar:native
DIST_SUBDIR=	eclipse
EXTRACT_ONLY=	WB_v${PORTVERSION}_UpdateSite_for_Eclipse3.7.zip

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A powerful and easy to use Java GUI designer for Eclipse

LICENSE=	EPL

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

WRKSRC=		${WRKDIR}

NO_STAGE=	yes
.include "${.CURDIR}/../eclipse/Makefile.plugins"

post-extract:
	@${CP} ${_DISTDIR}/org.eclipse.wb.os.freebsd_1.1.0.r37x201109091012.jar \
		${WRKSRC}/plugins

.include <bsd.port.mk>

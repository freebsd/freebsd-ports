# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	windowbuilder
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/windowbuilder/WB/release/,} \
		LOCAL/ale:native
MASTER_SITE_SUBDIR=	R201309271200
PKGNAMEPREFIX=	eclipse-
DISTFILES=	WB_v${PORTVERSION}_UpdateSite_for_Eclipse4.3.zip \
		org.eclipse.wb.os.freebsd_1.6.1.r37x201309092314.jar:native
DIST_SUBDIR=	eclipse
EXTRACT_ONLY=	WB_v${PORTVERSION}_UpdateSite_for_Eclipse4.3.zip

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Powerful and easy to use Java GUI designer for Eclipse

LICENSE=	EPL

RUN_DEPENDS=	eclipse:java/eclipse

WRKSRC=		${WRKDIR}

.include "${.CURDIR}/../eclipse/Makefile.plugins"

post-extract:
	@${CP} ${_DISTDIR}/org.eclipse.wb.os.freebsd_1.6.1.r37x201309092314.jar \
		${WRKSRC}/plugins

.include <bsd.port.mk>

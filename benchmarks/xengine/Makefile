# New ports collection makefile for:	xengine
# Date created:		17 January 1997
# Whom:			FURUSAWA,Kazuhisa <furusawa@com.cs.osakafu-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xengine
PORTVERSION=	1.0.1
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/comp.sources.x/volume09/xengine/
DISTFILES=	part01.z patch1.z

PATCH_DIST_STRIP=	-p1	# no ${PATCHFILES} but used below

MAINTAINER=	kazu@jp.freebsd.org

BUILD_DEPENDS=	gunshar:${PORTSDIR}/archivers/gshar+gunshar

DIST_SUBDIR=	xengine
NO_WRKSUBDIR=	yes
USE_IMAKE=	yes

EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=	#empty
EXTRACT_AFTER_ARGS=	| gunshar -d $(WRKDIR)

MAN1=		xengine.1

pre-patch:
	@cd $(WRKSRC) ; ${PATCH} ${PATCH_DIST_ARGS} < xengine.patch1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xengine
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/xengine
.endif
	@${ECHO} ""
	@${ECHO} "Example value:"
	@${ECHO} "   1067 RPMs with P100, Winner 2000PRO/X, resolution: 1152x900"
	@${ECHO} ""

.include <bsd.port.mk>

# New ports collection makefile for:	xengine
# Version required:	pl1
# Date created:		17 January 1997
# Whom:			FURUSAWA,Kazuhisa <furusawa@com.cs.osakafu-u.ac.jp>

DISTNAME=	xengine-pl1
PKGNAME=	xengine
CATEGORIES=	benchmarks x11
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/comp.sources.x/volume09/xengine/
DISTFILES=	part01.z patch1.z

MAINTAINER=	furusawa@com.cs.osakafu-u.ac.jp

BUILD_DEPENDS=	gunshar:${PORTSDIR}/archivers/gshar+gunshar

DIST_SUBDIR=	xengine
WRKSRC=		$(WRKDIR)
USE_IMAKE=	yes

EXTRACT_CMD=		zcat
EXTRACT_SUFX=		.z
EXTRACT_BEFORE_ARGS= 
EXTRACT_AFTER_ARGS=	| gunshar -d $(WRKDIR)

pre-patch:
	@cd $(WRKSRC) ; patch < xengine.patch1

post-install:
.if !defined(NOPORTDOCS)
	@mkdir -p $(PREFIX)/share/doc/xengine
	@install -c $(WRKSRC)/README $(PREFIX)/share/doc/xengine
.endif
	@${ECHO} "BTW: 1067 RPMs with P100, Winner 2000PRO/X, resol: 1152x900"

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	lm4tools
PORTVERSION=	0.1.3
CATEGORIES=	devel

MAINTAINER=	lev@FreeBSD.org
COMMENT=	TI Tiva C ARM microcontroller tools

LICENSE=		GPLv2 TIBSD
LICENSE_COMB=		multi
LICENSE_NAME_TIBSD=	Texas Instruments Software License Agreement
LICENSE_FILE_TIBSD=	${WRKSRC}/lmicdiusb/license.txt
LICENSE_PERMS_TIBSD=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	utzig
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	1cfd813

USES=		gmake

PLIST_FILES=	bin/lm4flash bin/lmicdi

.include <bsd.port.pre.mk>

do-build:
	@${GMAKE} -C ${WRKSRC}/lm4flash all
	@${GMAKE} -C ${WRKSRC}/lmicdiusb all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lm4flash/lm4flash ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/lmicdiusb/lmicdi ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.post.mk>

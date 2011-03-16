# New ports collection makefile for:   vpce
# Date created:        20 August 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	vpce
PORTVERSION=	0.3f
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://www.geocities.com/SiliconValley/Way/3340/ \
		http://freebsd.unixfreunde.de/sources/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}_freebsd
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PC Engine (TG16) emulator on X

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

NO_WRKSUBDIR=	yes
USE_XORG=	x11
NO_BUILD=	yes

STRIP=

PLIST_FILES=	bin/xvpce
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xvpce_03f_freebsd ${PREFIX}/bin/xvpce
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

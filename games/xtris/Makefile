# Created by: sec@42.org
# $FreeBSD$

PORTNAME=	xtris
PORTVERSION=	1.15
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://ftp.netbsd.org/pub/pkgsrc/distfiles/ \
		http://ftp.uni-erlangen.de/mirrors/gentoo/distfiles/ \
		http://www.iagora.com/~espel/xtris/ \
		ftp://quatramaran.ens.fr/pub/orabidoo/

PATCH_SITES=	ftp://ftp.42.org/pub/orphan/
PATCHFILES=	xtris-1.15-v6-19991218.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sec@42.org
COMMENT=	Multi-player version of a popular game for the X Window system

LICENSE=	GPLv2

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 3 months
EXPIRATION_DATE=	2020-01-10
RESTRICTED=	Possible trademark infringement
WRKSRC=		${WRKDIR}/xtris
USES=		xorg
USE_XORG=	x11 xext

MAKE_ENV=	IPV6_CFLAGS="-DINET6"

do-install:
.for i in xtbot xtris xtserv
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${i}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6
.endfor

.include <bsd.port.mk>

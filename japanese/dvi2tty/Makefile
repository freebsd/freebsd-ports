# Created by: Masafumi NAKANE <max@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dvi2tty
PORTVERSION=	5.0
CATEGORIES=	japanese print
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	hrs
PKGNAMESUFFIX=	-ascii
DISTNAME=	dvi2tty${PORTVERSION}

PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCH_DIST_STRIP=	-p1
PATCHFILES=	dvi2tty-ascii-jtex-patch dvi2tty.c-patch

MAINTAINER=	turutani@scphys.kyoto-u.ac.jp
COMMENT=	Character-based DVI file previewer

RUN_DEPENDS=	jless:${PORTSDIR}/japanese/less

CONFLICTS=	dvi2tty-[0-9]*

PLIST_FILES=	bin/jdvi2tty \
		bin/dvi2tty \
		bin/disdvi \
		man/man1/dvi2tty.1.gz \
		man/man1/jdvi2tty.1.gz

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} jdvi2tty disdvi ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dvi2tty.1 ${STAGEDIR}${PREFIX}/man/man1
	${LN} -sf ${PREFIX}/bin/jdvi2tty ${STAGEDIR}${PREFIX}/bin/dvi2tty
	${LN} -sf ${PREFIX}/man/man1/dvi2tty.1.gz \
		${STAGEDIR}${PREFIX}/man/man1/jdvi2tty.1.gz

.include <bsd.port.mk>

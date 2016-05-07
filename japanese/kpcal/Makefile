# Created by: Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
# $FreeBSD$

PORTNAME=	kpcal
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	LOCAL/cy

PATCH_SITES=	http://www.tamaru.kuee.kyoto-u.ac.jp/~tsuchiya/misc/kpcal/
PATCHFILES=	${PORTNAME}-${PORTVERSION}-20040518.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Make Calendar in Postscript format

ALL_TARGET=	kpcal

PLIST_FILES=	bin/kpcal man/man1/kpcal.1.gz

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} kpcal \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} kpcal.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>

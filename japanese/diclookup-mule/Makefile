# New ports collection makefile for:	diclookup-mule
# Date created:		31 Jan 1998
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	diclookup-mule
PORTVERSION=	2.3.3
CATEGORIES=	japanese elisp
MASTER_SITES=	ftp://ftp.math.s.chiba-u.ac.jp/tools/diclookup-mule/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	diclookup-mule-${PORTVERSION}-wave-patch.gz

MAINTAINER=	mita@jp.FreeBSD.org
COMMENT=	CDROM dictionary client for mule

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/non-cjk/fonts.dir:${PORTSDIR}/x11-fonts/etlfonts
BUILD_DEPENDS=	mule:${PORTSDIR}/japanese/mule-freewnn

post-install:
	${MKDIR} ${PREFIX}/lib/dserver/doc
	@${SED} s!PREFIX_DIR!${PREFIX}!g ${FILESDIR}/setup-diclookup.sh \
				> ${PREFIX}/lib/dserver/setup-diclookup.sh
	@${SED} s!PREFIX_DIR!${PREFIX}!g ${FILESDIR}/deinstall-diclookup.sh \
				> ${PREFIX}/lib/dserver/deinstall-diclookup.sh
	${INSTALL_DATA} ${FILESDIR}/README.diclookup-setup.txt \
				${PREFIX}/lib/dserver/doc
	${INSTALL_DATA} ${WRKSRC}/README \
				${PREFIX}/lib/dserver/doc/README.diclookup-mule
	${INSTALL_DATA} ${WRKSRC}/README.sirup \
				${PREFIX}/lib/dserver/doc/
	${INSTALL_DATA} ${WRKSRC}/lib/README \
			${PREFIX}/lib/dserver/doc/README.diclookup-mule.lib

.include <bsd.port.mk>

# New ports collection makefile for:	diclookup-emacs20
# Date created:		31 Jan 1998
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	diclookup
PORTVERSION=	2.3.4b8
CATEGORIES=	japanese elisp
MASTER_SITES=	ftp://ftp.math.s.chiba-u.ac.jp/tools/diclookup-mule/beta/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	diclookup-mule-${PORTVERSION}

MAINTAINER=	mita@FreeBSD.org

RUN_DEPENDS=	${X11BASE}/share/doc/intlfonts-1.2/README:${PORTSDIR}/x11-fonts/intlfonts

WRKSRC=		${WRKDIR}/diclookup-mule-${PORTVERSION}
EMACS_PORT_NAME?=	emacs20
MAKE_ARGS+=	LISPDIR="${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/diclookup"
DOC_DIR=	${PREFIX}/share/doc/diclookup-emacs20

pre-install:
	${MKDIR} ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/diclookup
post-install:
	${MKDIR} ${DOC_DIR}
	@${SED} s!PREFIX_DIR!${PREFIX}!g ${FILESDIR}/setup-diclookup.sh \
				> ${DOC_DIR}/setup-diclookup.sh
	@${SED} s!PREFIX_DIR!${PREFIX}!g ${FILESDIR}/deinstall-diclookup.sh \
				> ${DOC_DIR}/deinstall-diclookup.sh
	${INSTALL_DATA} ${FILESDIR}/README.diclookup-setup.txt \
				${DOC_DIR}/
	${INSTALL_DATA} ${WRKSRC}/README \
				${DOC_DIR}/README.diclookup-mule
	${INSTALL_DATA} ${WRKSRC}/README.sirup \
				${DOC_DIR}/
	${INSTALL_DATA} ${WRKSRC}/lib/README \
			${DOC_DIR}/README.diclookup-mule.lib

.include <bsd.port.mk>

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
COMMENT=	CDROM dictionary client for emacs. (needs ndtpd or dserver package)

RUN_DEPENDS=	${FONTSDIR}/a18rk.pcf.gz:${PORTSDIR}/x11-fonts/intlfonts

WRKSRC=		${WRKDIR}/diclookup-mule-${PORTVERSION}
EMACS_PORT_NAME?=	emacs20
MAKE_ARGS+=	LISPDIR="${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/diclookup"
FONTSDIR=	${X11BASE}/lib/X11/fonts/local
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

pre-install:
	${MKDIR} ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/diclookup

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${SED} s!PREFIX_DIR!${PREFIX}!g ${FILESDIR}/setup-diclookup.sh \
				> ${DOCSDIR}/setup-diclookup.sh
	@${SED} s!PREFIX_DIR!${PREFIX}!g ${FILESDIR}/deinstall-diclookup.sh \
				> ${DOCSDIR}/deinstall-diclookup.sh
	${INSTALL_DATA} ${FILESDIR}/README.diclookup-setup.txt \
				${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README \
				${DOCSDIR}/README.diclookup-mule
	${INSTALL_DATA} ${WRKSRC}/README.sirup \
				${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/lib/README \
			${DOCSDIR}/README.diclookup-mule.lib
.endif

.include <bsd.port.mk>

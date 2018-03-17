# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$
#
# This is a set of Makefile macros which allow to build the
# localized language packages for devel/eric6:
# german/eric6, russian/eric6, devel/es-eric6

.include "${.CURDIR}/../../devel/eric6/bsd.eric6.mk"

PKGNAMEPREFIX=	${I18N_LANG}-
DISTNAME=	${PORTNAME}-i18n-${I18N_LANG}-${PORTVERSION}

INSTALL_CMD=	install-i18n.py -p ${STAGEDIR}
NO_ARCH=	yes
PLIST_FILES=	${DATADIR}/i18n/${PORTNAME}_${I18N_LANG}.qm

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/i18n
	${INSTALL_DATA} ${WRKSRC}/eric/i18n/${PORTNAME}_${I18N_LANG}.qm ${STAGEDIR}${DATADIR}/i18n/

.include <bsd.port.mk>

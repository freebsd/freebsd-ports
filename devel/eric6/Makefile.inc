# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$
#
# This is a set of Makefile macros which allow to build the
# localized language packages for devel/eric6:
# german/eric6, russian/eric6, devel/es-eric6

.include "${.CURDIR}/../../devel/eric6/bsd.eric6.mk"

PKGNAMEPREFIX=	${I18N_LANG}-
DISTNAME=	${PORTNAME}-i18n-${I18N_LANG}-${PORTVERSION}

COMMENT=	${I18N_LANG} i18n package for Eric6 IDE

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	${DATADIR}/i18n/${PORTNAME}_${I18N_LANG}.qm

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/i18n
	${INSTALL_DATA} ${WRKSRC}/eric/eric6/i18n/${PORTNAME}_${I18N_LANG}.qm ${STAGEDIR}${DATADIR}/i18n/

.include <bsd.port.mk>

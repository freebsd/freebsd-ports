# New ports collection makefile for:	koffice-i18n
# Date created:				27 April 2003
# Whom:					Michael Nottebrock <michaelnottebrock@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	koffice-i18n
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	editors kde
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Localized messages and documentation for KDE

RUN_DEPENDS+=\
	${LOCALBASE}/share/locale/km/LC_MESSAGES/example.mo:${PORTSDIR}/editors/koffice-i18n-km\
	${LOCALBASE}/share/locale/ar/LC_MESSAGES/kword.mo:${PORTSDIR}/arabic/koffice-i18n\
	${LOCALBASE}/share/locale/de/LC_MESSAGES/kword.mo:${PORTSDIR}/german/koffice-i18n\
	${LOCALBASE}/share/locale/fr/LC_MESSAGES/kword.mo:${PORTSDIR}/french/koffice-i18n\
	${LOCALBASE}/share/locale/hu/LC_MESSAGES/kword.mo:${PORTSDIR}/hungarian/koffice-i18n\
	${LOCALBASE}/share/locale/he/LC_MESSAGES/kword.mo:${PORTSDIR}/hebrew/koffice-i18n\
	${LOCALBASE}/share/locale/ja/LC_MESSAGES/kword.mo:${PORTSDIR}/japanese/koffice-i18n\
	${LOCALBASE}/share/locale/pl/LC_MESSAGES/kword.mo:${PORTSDIR}/polish/koffice-i18n\
	${LOCALBASE}/share/locale/pt/LC_MESSAGES/kword.mo:${PORTSDIR}/portuguese/koffice-i18n\
	${LOCALBASE}/share/locale/pt_BR/LC_MESSAGES/kword.mo:${PORTSDIR}/portuguese/koffice-i18n-pt_BR\
	${LOCALBASE}/share/locale/ru/LC_MESSAGES/kword.mo:${PORTSDIR}/russian/koffice-i18n\
	${LOCALBASE}/share/locale/uk/LC_MESSAGES/kword.mo:${PORTSDIR}/ukrainian/koffice-i18n\
	${LOCALBASE}/share/locale/zh_CN/LC_MESSAGES/kword.mo:${PORTSDIR}/chinese/koffice-i18n-zh_CN \
	${LOCALBASE}/share/locale/zh_TW/LC_MESSAGES/kword.mo:${PORTSDIR}/chinese/koffice-i18n-zh_TW

.for LANG in af bg br bs ca cs cy da el en_GB eo es et eu fa fi ga gl hi hsb is it \
	lo lt lv mk ms mt nb nl nn ro se sk sl sr sr_Latn sv ta tg th tr uz ven xh zu
RUN_DEPENDS+=\
${LOCALBASE}/share/locale/${LANG}/LC_MESSAGES/kword.mo:${PORTSDIR}/editors/koffice-i18n-${LANG}
.endfor

USE_KDELIBS_VER=3
NO_BUILD=	yes
KDE_I18N=	yes

do-install:	# none

.include <bsd.port.mk>

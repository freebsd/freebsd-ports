# New ports collection makefile for:    koffice-kde4-l10n
# Date created:                         28 November 2009
# Whom:                                 Dima Panov <fluffy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koffice-l10n
PORTVERSION=	${KOFFICE2_VERSION}
CATEGORIES=	editors kde
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Localized messages and documentation for KOffice2

NO_BUILD=	yes
# NO_INSTALL=	yes
USE_KDE4=	kdeprefix

KOFFICE2_LANG_ALL=	ca ca@valencia da de el en_GB es et fr gl it ja kk \
			nb nds nl pl pt pt_BR sv tr uk zh_CN zh_TW

ca@valencia_PORT=	editors/koffice-kde4-l10n-ca_valencia
de_PORT=	german/koffice-kde4-l10n
fr_PORT=	french/koffice-kde4-l10n
ja_PORT=	japanese/koffice-kde4-l10n
pl_PORT=	polish/koffice-kde4-l10n
pt_BR_PORT=	portuguese/koffice-kde4-l10n-pt_BR
pt_PORT=	portuguese/koffice-kde4-l10n
uk_PORT=	ukrainian/koffice-kde4-l10n
zh_CN_PORT=	chinese/koffice-kde4-l10n-zh_CN
zh_TW_PORT=	chinese/koffice-kde4-l10n-zh_TW

.include <${.CURDIR}/../../misc/kde4-l10n/files/kde4-lang-names>
nb_NAME=	Norwegian Bokmal

OPTIONS=	ALL "All localizations" on
.for lang in ${KOFFICE2_LANG_ALL}
${lang}_DETECT?=	${KDE4_PREFIX}/share/locale/${lang}/LC_MESSAGES/koffice.mo
${lang}_PORT?=		editors/koffice-kde4-l10n-${lang}
${lang}_NAME?=		${lang}
${lang}_OPTION=		${lang:S/@/_/}
OPTIONS+=	${${lang}_OPTION} "${${lang}_NAME} localization" off
.endfor

.include <bsd.port.options.mk>

.for lang in ${KOFFICE2_LANG_ALL}
.if defined(WITH_ALL) || defined(WITH_${${lang}_OPTION})
RUN_DEPENDS+=	${${lang}_DETECT}:${PORTSDIR}/${${lang}_PORT}
.endif
.endfor

do-install:
	${DO_NADA}

.include <bsd.port.mk>

# New ports collection makefile for:	Japanized KDE2
# Date created:		28 August 2001
# Whom:			SASAKI Katuhiro <sahiro@crest.ocn.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	japanese x11 kde
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	sahiro@crest.ocn.ne.jp

LIB_DEPENDS=	qt2.4:${PORTSDIR}/japanese/qt23 \
		kdecore.4:${PORTSDIR}/japanese/kdelibs2 \
		konq.4:${PORTSDIR}/japanese/kdebase2
RUN_DEPENDS=	kppp:${PORTSDIR}/japanese/kdenetwork2 \
		dcop_kate:${PORTSDIR}/japanese/kdeaddons \
		${LOCALBASE}/share/locale/ja/entry.desktop:${PORTSDIR}/japanese/kde2-i18n \
		${LOCALBASE}/share/locale/ja/LC_MESSAGES/koshell.mo:${PORTSDIR}/japanese/koffice-i18n

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>

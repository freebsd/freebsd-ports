# New ports collection makefile for:	gdesklets-psi_themes
# Date created:				21 September 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	themes
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-psi_
DISTNAME=	PsiDisplayPackage-${DISTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	Themes from the Psi Display Package

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets

USE_X_PREFIX=	yes

DISTVERSION=	20040420
NAME_THEMES=	Psi-Disp-Themes
DATADIR=	${PREFIX}/share/gnome
WRKSRC=		${WRKDIR}/Themes
NO_BUILD=	yes

do-install:
	@cd ${WRKSRC}; \
		${FIND} . -type d -exec ${MKDIR} ${DATADIR}/gdesklets/Themes/\{} \; ;\
		${FIND} . -type f -exec ${INSTALL_DATA} \{} ${DATADIR}/gdesklets/Themes/\{} \;

.include <bsd.port.mk>

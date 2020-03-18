# Created by: kipz <somicide@gmail.com>
# $FreeBSD$

PORTNAME=	gitg
PORTVERSION=	0.0.8
PORTREVISION=	2
CATEGORIES=	devel deskutils gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-based git repository viewer (gtk2 version)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_11_powerpc64=	fails to link on powerpc64 elfv1: gitg-branch-actions.o(.text+0x46c): unresolvable R_PPC64_REL24 relocation against symbol gitg_revision_get_subject
BROKEN_FreeBSD_12_powerpc64=	fails to link on powerpc64 elfv1: gitg-branch-actions.o(.text+0x46c): unresolvable R_PPC64_REL24 relocation against symbol gitg_revision_get_subject

RUN_DEPENDS=	git:devel/git

CONFLICTS=	gitg-[0-9]*

USES=		gmake gnome libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gconf2 gtk20 gtksourceview2 intlhack
INSTALL_TARGET=	install-strip

INSTALLS_ICONS=	yes
GCONF_SCHEMAS=	gitg.schemas

PORTSCOUT=	limit:^0\.0\.

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools
NLS_CONFIGURE_ENABLE=nls
NLS_CPPFLAGS=	-I${LOCALBASE}/include
NLS_LIBS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>

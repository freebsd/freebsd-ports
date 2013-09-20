# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	scim-hangul
PORTVERSION=	0.4.0
CATEGORIES=	korean
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	SCIM IMEngine module for Korean(Hangul) input

LICENSE=	GPLv2

LIB_DEPENDS=	hangul:${PORTSDIR}/korean/libhangul \
		scim-1.0:${PORTSDIR}/textproc/scim

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		pkgconfig

OPTIONS_DEFINE=	NLS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.mk>

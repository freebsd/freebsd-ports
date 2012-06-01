# New ports collection makefile for:    ko-scim-hangul
# Date created:		13 Oct 2005
# Whom:			CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scim-hangul
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	korean
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	SCIM IMEngine module for Korean(Hangul) input

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	hangul.1:${PORTSDIR}/korean/libhangul
RUN_DEPENDS=	scim:${PORTSDIR}/textproc/scim

USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure ${WRKSRC}/skim/configure

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.mk>

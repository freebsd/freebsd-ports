# New ports collection makefile for:	tpb
# Date created:				Fri Jun 10 00:38:03 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	tpb
PORTVERSION=	0.6.4
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	On-Screen-Display for hotkeys of IBM ThinkPads

LIB_DEPENDS=	xosd.4:${PORTSDIR}/misc/xosd

ONLY_FOR_ARCHS=	i386 amd64

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_BISON=	build

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE}

MAN1=		tpb.1

.ifndef(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/cfg.h \
		${WRKSRC}/man/tpb.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/tpbrc ${PREFIX}/etc/tpbrc.default
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/callback_example.sh ${DOCSDIR}
.endif

.include <bsd.port.mk>

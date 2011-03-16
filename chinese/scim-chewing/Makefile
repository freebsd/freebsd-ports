# New ports collection makefile for:    zh-scim-chewing
# Date created:		4 Dec 2004
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	scim-chewing
PORTVERSION=	0.3.3
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	http://chewing.csie.net/download/scim/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM chewing Chinese input methods

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	chewing.3:${PORTSDIR}/chinese/libchewing

BROKEN=		does not configure

USE_BZIP2=	yes
USE_GNOME=	intltool
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-D__STDC_ISO_10646__ -I${LOCALBASE}/include"

post-patch:
	@${REINPLACE_CMD} -e 's,@DATADIRNAME@,share,g' ${WRKSRC}/po/Makefile.in.in

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.mk>

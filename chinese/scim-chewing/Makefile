# New ports collection makefile for:    zh-scim-chewing
# Date created:		4 Dec 2004
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	scim-chewing
PORTVERSION=	0.3.1
PORTREVISION=	5
CATEGORIES=	chinese
MASTER_SITES=	http://chewing.csie.net/download/scim/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM chewing Chinese input methods

RUN_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	chewing.3:${PORTSDIR}/chinese/libchewing
BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-D__STDC_ISO_10646__ -I${LOCALBASE}/include"

post-patch:
	@${REINPLACE_CMD} -e 's,/1.0.0/,/,g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's,@DATADIRNAME@,share,g' ${WRKSRC}/po/Makefile.in.in

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.mk>

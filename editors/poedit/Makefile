# ex:ts=8
# New ports collection makefile for:	poedit
# Date created:			Mar 27, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/editors/poedit/Makefile,v 1.2 2006/10/05 07:03:09 mezz Exp $
#

PORTNAME=	poedit
PORTVERSION=	1.4.6.1
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.4.6/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Gettext catalogs (.po files) editor

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell

USE_GNOME=	gnometarget pkgconfig
USE_WX=		2.8+
WX_CONF_ARGS=	absolute
WX_UNICODE=	yes
USE_BDB=	yes
WITH_BDB_HIGHEST=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		WXRC="${WXRC_CMD}"
INSTALLS_ICONS=	yes

MAN1=		poedit.1

CPPFLAGS=	-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${BDB_LIB_DIR} -L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's/for version in .*;/for version in ${BDB_VER};/ ; \
		 s/-ldb-$$version/-l${BDB_LIB_NAME}/' ${WRKSRC}/configure

.include <bsd.port.post.mk>

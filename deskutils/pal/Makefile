# Ports collection makefile for:	pal
# Date created:				Mar 16, 2004
# Whom:					Herbert J. Skuhra <h.skuhra@gmail.com>
#
# $FreeBSD$

PORTNAME=	pal
PORTVERSION=	0.3.4
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	palcal
EXTRACT_SUFX=	.tgz

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	A calendar application

USE_GNOME=	glib20
USE_GETTEXT=	yes
USE_GMAKE=	yes
ALL_TARGET=
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

MAN1=		pal.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS=	readline.6:${PORTSDIR}/devel/readline
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,prefix = /usr,prefix = ${PREFIX},g" ${WRKSRC}/Makefile.defs

post-build:
	${REINPLACE_CMD} -e "s,VERSION,${PORTVERSION},g" ${WRKDIR}/${PORTNAME}-${PORTVERSION}/pal.1.template

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pal ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/share/*.pal ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/pal.conf ${DATADIR}
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/pal.1.template ${PREFIX}/man/man1/pal.1

.include <bsd.port.post.mk>

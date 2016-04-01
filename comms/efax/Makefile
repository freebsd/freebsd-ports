# Created by: MITA Yoshio <mita@FreeBSD.org>
# $FreeBSD$

PORTNAME=	efax-0.9a
PORTVERSION=	001114a7
PORTREVISION=	7
CATEGORIES=	comms
MASTER_SITES=	http://shino.pos.to/linux/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fax send/receive program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	xloadimage:x11/xloadimage

DOCSDIR=	${PREFIX}/share/doc/efax
PORTDOCS=	README printcap.sample efax.html fax.html
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"
SUB_FILES=	pkg-message

CONFLICTS=	efax-gtk-*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,$$(PREFIX),${STAGEDIR}&,g' ${WRKSRC}/Makefile

post-build:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/fax

post-install:
	${INSTALL_DATA} ${WRKSRC}/efax.rc.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/efax.rc.sample.ja ${STAGEDIR}${PREFIX}/etc/efax.rc.ja.sample
	@${MKDIR} ${STAGEDIR}/var/spool/fax/incoming
	${TOUCH} ${STAGEDIR}/var/spool/fax/incoming/.keepme
	@${MKDIR} ${STAGEDIR}/var/spool/fax/outgoing
	${TOUCH} ${STAGEDIR}/var/spool/fax/outgoing/lock

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# Created by: MITA Yoshio <mita@FreeBSD.org>
# $FreeBSD$

PORTNAME=	efax-0.9a
PORTVERSION=	001114a7
PORTREVISION=	5
CATEGORIES=	comms
MASTER_SITES=	http://shino.pos.to/linux/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fax send/receive program

RUN_DEPENDS=	xloadimage:${PORTSDIR}/x11/xloadimage

USES=		gmake
MAN1=		fax.1 \
		efax.1 \
		efix.1
DOCSDIR=	${PREFIX}/share/doc/efax
PORTDOCS=	COPYING README printcap.sample efax.html fax.html
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

CONFLICTS=	efax-gtk-*

NO_STAGE=	yes
post-build:
	${MV} ${WRKSRC}/fax ${WRKSRC}/fax.orig
	${CAT} ${WRKSRC}/fax.orig | ${SED} -e s!%%PREFIX%%!${PREFIX}!g > \
		${WRKSRC}/fax

.include <bsd.port.options.mk>

post-install:
	${INSTALL_DATA} ${WRKSRC}/efax.rc.sample ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/efax.rc.sample.ja ${PREFIX}/etc
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${ECHO_CMD}
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_CMD}

.include <bsd.port.mk>

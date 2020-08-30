# Created by: MITA Yoshio <mita@FreeBSD.org>
# $FreeBSD$

PORTNAME=	efax
DISTVERSION=	0.9a-001114a7
PORTREVISION=	9
CATEGORIES=	comms
MASTER_SITES=	http://shino.pos.to/linux/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fax send/receive program

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	xloadimage:x11/xloadimage

DOCSDIR=	${PREFIX}/share/doc/efax
PORTDOCS=	README printcap.sample efax.html fax.html
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"
SUB_FILES=	pkg-message

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

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

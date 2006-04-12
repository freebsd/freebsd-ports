# New ports collection makefile for:   totd
# Date created:        17 Nov 2000
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	totd
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DNS proxy that supports IPv6 <==> IPv4 record translation

USE_RC_SUBR=	yes
GNU_CONFIGURE=	yes

MAN8=		totd.8

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
EXTRA_PATCHES=	${FILESDIR}/extra-patch-ne_mesg.c \
		${FILESDIR}/extra-patch-tcp_response.c
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d' ${WRKSRC}/${MAKEFILE}.in
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's/%zd/%d/g' ${WRKSRC}/*.c
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/totd.conf.sample ${PREFIX}/etc
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/totd.sh > ${PREFIX}/etc/rc.d/totd.sh
	@${CHMOD} ${BINMODE} ${PREFIX}/etc/rc.d/totd.sh

.include <bsd.port.post.mk>

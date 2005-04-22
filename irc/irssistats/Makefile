# New ports collection makefile for:	irssistats
# Date created:			14 Feb 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	irssistats
PORTVERSION=	0.70
CATEGORIES=	irc
MASTER_SITES=	http://royale.zerezo.com/irssistats/

MAINTAINER=	az@inec.ru
COMMENT=	Generate IRC statistics based on irssi logs

USE_REINPLACE=	yes

MAKE_ARGS+=	DATADIR="${DATADIR}" DOCSDIR="${DOCSDIR}" EXAMPLESDIR="${EXAMPLESDIR}" PREFIX="${PREFIX}" \
		CC="${CC}" CFLAGS="${CFLAGS}"

MAN1=	irssistats.1

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/irssistats.conf|${PREFIX}/etc/irssistats.conf|g' ${WRKSRC}/irssistats.c

.if defined(NOPORTDOCS)
MAKE_ARGS+=	NOPORTDOCS="${NOPORTDOCS}"
.endif

.include <bsd.port.mk>

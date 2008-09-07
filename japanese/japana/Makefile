# New ports collection makefile for:	japana
# Date created:		04 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	japana
PORTVERSION=	2.0.6
CATEGORIES=	japanese www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web proxy converting Japanese into Romaji

RUN_DEPENDS=	*p5-Text-Kakasi>=2:${PORTSDIR}/japanese/p5-Text-Kakasi \
		p5-AppConfig>=0:${PORTSDIR}/devel/p5-AppConfig \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USE_PERL5=	yes
MAN1=	${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME} etc/${PORTNAME}.conf.default

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' ${WRKSRC}/${PORTNAME}* ${WRKSRC}/default.conf

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
	@${INSTALL_DATA} ${WRKSRC}/default.conf ${PREFIX}/etc/${PORTNAME}.conf.default

.include <bsd.port.mk>

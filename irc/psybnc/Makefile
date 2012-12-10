# New ports collection makefile for:	psybnc
# Date created:		24 November 2002
# Whom:			Mina Naguib <webmaster@topfx.com>
#
# $FreeBSD$
#

PORTNAME=	psybnc
DISTVERSION=	2.3.2-9
CATEGORIES=	irc ipv6
MASTER_SITES=	http://www.psybnc.at/download/beta/ CENKES
DISTNAME=	psyBNC-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extremely powerful IRC bouncer

WRKSRC=		${WRKDIR}/psybnc
PSYBASE=	${PREFIX}/psybnc
MAKE_ARGS=	PSYBASE=${PSYBASE}
IS_INTERACTIVE=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's#=help/#=${PSYBASE}/help/#' ${WRKSRC}/lang/*

do-configure:
	@cd ${WRKSRC} && make menuconfig

do-install:
	@${INSTALL} -d ${PSYBASE}/lang/ ${PSYBASE}/key/ ${PSYBASE}/help/
	@${INSTALL_DATA} ${WRKSRC}/lang/INFO ${PSYBASE}/lang/
	@${INSTALL_DATA} ${WRKSRC}/lang/*.lng ${PSYBASE}/lang/
	@if [ -f ${WRKSRC}/key/psybnc.cert.pem ]; then ${INSTALL_DATA} ${WRKSRC}/key/psybnc.cert.pem ${PSYBASE}/key/; fi
	@if [ -f ${WRKSRC}/key/psybnc.key.pem ]; then ${INSTALL_DATA} ${WRKSRC}/key/psybnc.key.pem ${PSYBASE}/key/; fi
	@if [ -f ${WRKSRC}/key/psybnc.req.pem ]; then ${INSTALL_DATA} ${WRKSRC}/key/psybnc.req.pem ${PSYBASE}/key/; fi
	@${INSTALL_DATA} ${WRKSRC}/help/*.TXT ${PSYBASE}/help/
	@${INSTALL_DATA} ${WRKSRC}/help/*.DEU ${PSYBASE}/help/
	@${INSTALL_DATA} ${WRKSRC}/help/*.ITA ${PSYBASE}/help/
	${INSTALL_PROGRAM} ${WRKSRC}/psybnc ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/psybnc.conf ${PREFIX}/etc/psybnc.conf.sample

.include <bsd.port.post.mk>

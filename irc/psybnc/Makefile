# Created by: Mina Naguib <webmaster@topfx.com>
# $FreeBSD$

PORTNAME=	psybnc
DISTVERSION=	2.3.2-9
CATEGORIES=	irc ipv6
MASTER_SITES=	http://www.psybnc.at/download/beta/ CENKES
DISTNAME=	psyBNC-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extremely powerful IRC bouncer

WRKSRC=		${WRKDIR}/psybnc
PSYBASE?=	${PREFIX}/psybnc
MAKE_ARGS=	PSYBASE=${PSYBASE}
SUB_FILES=	pkg-message
SUB_LIST=	PSYBASE=${PSYBASE}
PLIST_SUB=	PSYBASE=${PSYBASE:S,^${PREFIX}/,,}

OPTIONS_DEFINE=	MENUCONFIG
MENUCONFIG_DESC=Configure using menu

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMENUCONFIG}
IS_INTERACTIVE=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#=help/#=${PSYBASE}/help/#' ${WRKSRC}/lang/*

do-configure:
.if ${PORT_OPTIONS:MMENUCONFIG}
	@cd ${WRKSRC} && make menuconfig
.else
# Fool makefile.out into believing certs are unnecessary
	@${TOUCH} ${WRKSRC}/key/psybnc.cert.pem
.endif

do-install:
	@${INSTALL} -d ${PSYBASE}/lang/ ${PSYBASE}/key/ ${PSYBASE}/help/
	@${INSTALL_DATA} ${WRKSRC}/lang/INFO ${PSYBASE}/lang/
	@${INSTALL_DATA} ${WRKSRC}/lang/*.lng ${PSYBASE}/lang/
	@${INSTALL_DATA} ${WRKSRC}/src/ssl.cnf ${PSYBASE}/key/
	@${INSTALL_DATA} ${WRKSRC}/help/*.TXT ${PSYBASE}/help/
	@${INSTALL_DATA} ${WRKSRC}/help/*.DEU ${PSYBASE}/help/
	@${INSTALL_DATA} ${WRKSRC}/help/*.ITA ${PSYBASE}/help/
	${INSTALL_PROGRAM} ${WRKSRC}/psybnc ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/psybnc.conf ${PREFIX}/etc/psybnc.conf.sample

post-install:
	@if [ -f ${WRKSRC}/key/psybnc.req.pem ]; then \
	    ${INSTALL_DATA} ${WRKSRC}/key/psybnc.cert.pem ${PSYBASE}/key/; \
	    ${INSTALL_DATA} ${WRKSRC}/key/psybnc.key.pem ${PSYBASE}/key/; \
	    ${INSTALL_DATA} ${WRKSRC}/key/psybnc.req.pem ${PSYBASE}/key/; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

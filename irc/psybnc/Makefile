# Created by: Mina Naguib <webmaster@topfx.com>
# $FreeBSD$

PORTNAME=	psybnc
DISTVERSION=	2.3.2-9
PORTREVISION=	2
CATEGORIES=	irc ipv6
MASTER_SITES=	http://www.psybnc.at/download/beta/
DISTNAME=	psyBNC-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful IRC bouncer

LICENSE=	GPLv1+ # though COPYING is GPLv2

BROKEN_powerpc64=	Does not build

USE_OPENSSL=	yes
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
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000024
	@${REINPLACE_CMD} -e 's,gcc,clang -Wno-return-type,g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,gcc,clang -Wno-return-type,g' ${WRKSRC}/tools/autoconf.c
.endif

do-configure:
.if ${PORT_OPTIONS:MMENUCONFIG}
	cd ${WRKSRC} && make menuconfig
.else
# Fool makefile.out into believing certs are unnecessary
	${TOUCH} ${WRKSRC}/key/psybnc.cert.pem
.endif

do-install:
	${INSTALL} -d ${STAGEDIR}${PSYBASE}/lang/ ${STAGEDIR}${PSYBASE}/key/ ${STAGEDIR}${PSYBASE}/help/
	${INSTALL_DATA} ${WRKSRC}/lang/INFO ${STAGEDIR}${PSYBASE}/lang/
	${INSTALL_DATA} ${WRKSRC}/lang/*.lng ${STAGEDIR}${PSYBASE}/lang/
	${INSTALL_DATA} ${WRKSRC}/src/ssl.cnf ${STAGEDIR}${PSYBASE}/key/
	${INSTALL_DATA} ${WRKSRC}/help/*.TXT ${STAGEDIR}${PSYBASE}/help/
	${INSTALL_DATA} ${WRKSRC}/help/*.DEU ${STAGEDIR}${PSYBASE}/help/
	${INSTALL_DATA} ${WRKSRC}/help/*.ITA ${STAGEDIR}${PSYBASE}/help/
	${INSTALL_PROGRAM} ${WRKSRC}/psybnc ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/psybnc.conf ${STAGEDIR}${PREFIX}/etc/psybnc.conf.sample

post-install:
	if [ -f ${WRKSRC}/key/psybnc.req.pem ]; then \
	    ${INSTALL_DATA} ${WRKSRC}/key/psybnc.cert.pem ${STAGEDIR}${PSYBASE}/key/; \
	    ${INSTALL_DATA} ${WRKSRC}/key/psybnc.key.pem ${STAGEDIR}${PSYBASE}/key/; \
	    ${INSTALL_DATA} ${WRKSRC}/key/psybnc.req.pem ${STAGEDIR}${PSYBASE}/key/; \
	fi

.include <bsd.port.mk>

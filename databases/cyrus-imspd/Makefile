# New ports collection makefile for:		cyrus-imspd
# Date created:					Jan 4th 2001
# Whom:						damien@tougas.net
#
# $FreeBSD$
#

PORTNAME=	cyrus-imspd
PORTVERSION=	1.6a5
CATEGORIES=	databases mail
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The cyrus IMSP (Internet Message Support Protocol) server

LIB_DEPENDS=	sasl.8:${PORTSDIR}/security/cyrus-sasl
BUILD_DEPENDS=	${LOCALBASE}/sbin/pwcheck:${PORTSDIR}/security/cyrus-sasl

USE_REINPLACE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-sasldir=${LOCALBASE} \
		--with-auth=unix

pre-configure:
		${REINPLACE_CMD} -e "s|<sasl.h>|<sasl1/sasl.h>|" \
			${WRKSRC}/configure

post-install:
		${INSTALL_SCRIPT} ${FILESDIR}/imspd.sh \
			${PREFIX}/etc/rc.d/imspd.sh
		${INSTALL_DATA} ${FILESDIR}/imspd.conf \
			${PREFIX}/lib/sasl/imspd.conf
		${MKDIR} /var/imsp
		${INSTALL_DATA} ${WRKSRC}/imsp/options.sample \
			/var/imsp/options.dist
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/imspd
		${INSTALL_DATA} ${WRKSRC}/notes/Setup-instructions \
			${PREFIX}/share/doc/imspd
		${INSTALL_DATA} ${WRKSRC}/notes/option.registry \
			${PREFIX}/share/doc/imspd
		${INSTALL_DATA} ${WRKSRC}/notes/Changes-Todo \
			${PREFIX}/share/doc/imspd
		${INSTALL_DATA} ${WRKSRC}/notes/imsp.implementation \
			${PREFIX}/share/doc/imspd
		${INSTALL_DATA} ${WRKSRC}/notes/imsp.implementation.updates \
			${PREFIX}/share/doc/imspd
.endif
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

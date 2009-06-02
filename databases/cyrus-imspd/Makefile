# New ports collection makefile for:		cyrus-imspd
# Date created:					Jan 4th 2001
# Whom:						damien@tougas.net
#
# $FreeBSD$
#

PORTNAME=	cyrus-imspd
PORTVERSION=	1.8
CATEGORIES=	databases mail
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		http://ftp.kfki.hu/packages/mail/cyrus/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The cyrus IMSP (Internet Message Support Protocol) server

LIB_DEPENDS=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2

GNU_CONFIGURE=	YES
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-sasldir=${LOCALBASE} \
		--with-sasl=${LOCALBASE} \
		--with-auth=unix

USE_RC_SUBR=	imspd
DOCSDIR=	${PREFIX}/share/doc/imspd

post-patch:
		${REINPLACE_CMD} -e "s|<sasl.h>|<sasl2/sasl.h>|" \
			${WRKSRC}/configure

post-install:
		${INSTALL_DATA} ${FILESDIR}/imspd.conf \
			${PREFIX}/lib/sasl2/imspd.conf
		${MKDIR} /var/imsp
		${INSTALL_DATA} ${WRKSRC}/imsp/options.sample \
			/var/imsp/options.dist
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/notes/Setup-instructions \
				${WRKSRC}/notes/option.registry \
				${WRKSRC}/notes/Changes-Todo \
				${WRKSRC}/notes/imsp.implementation \
				${WRKSRC}/notes/imsp.implementation.updates \
			${DOCSDIR}
.endif
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

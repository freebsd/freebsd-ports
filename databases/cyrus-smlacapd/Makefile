# New ports collection makefile for:		cyrus-smlacapd
# Date created:					May 11th 2004
# Whom:						g.gonter@ieee.org
#
# $FreeBSD$
#

PORTNAME=	cyrus-smlacapd
PORTVERSION=	0.5
CATEGORIES=	databases mail
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/

MAINTAINER=	g.gonter@ieee.org
COMMENT=	The cyrus ACAP (Application Configuration Access Protocol) server

LIB_DEPENDS=	sasl.8:${PORTSDIR}/security/cyrus-sasl
BUILD_DEPENDS=	sml:${PORTSDIR}/lang/sml-nj

USE_REINPLACE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-cyrus-prefix=${PREFIX}/cyrus \
		--with-sasldir=${LOCALBASE}/lib

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

ACAPD_DOC=	${PREFIX}/share/doc/acapd

pre-configure:
	${REINPLACE_CMD} -e "s#sasl.h#sasl1/sasl.h#" ${WRKSRC}/configure
	${REINPLACE_CMD} -e "s#<sasl.h>#<sasl1/sasl.h>#" \
		${WRKSRC}/actest/actest.c ${WRKSRC}/api/acap.c \
		${WRKSRC}/api/acap.h ${WRKSRC}/frontend/frontend.c \
		${WRKSRC}/lib/imclient.c ${WRKSRC}/lib/prot.h

pre-su-install:
		${MKDIR} -m 0755 -p ${PREFIX}/cyrus
		${MKDIR} -m 0755 -p ${PREFIX}/include/cyrus

post-install:
	${INSTALL} ${LOCALBASE}/lib/sml-nj/bin/.run/run.x86-freebsd ${PREFIX}/cyrus/bin
	${INSTALL_SCRIPT} ${FILESDIR}/cyrus_smlacapd_backend \
		${PREFIX}/etc/rc.d/cyrus_smlacapd_backend.sample

	${MKDIR} ${ACAPD_DOC}
	${INSTALL_DATA} ${FILESDIR}/acapd.conf-sample ${ACAPD_DOC}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/doc/install.html ${ACAPD_DOC}
	${TR} '\r' '\n' < ${WRKSRC}/doc/draft-ietf-acap-book-03.txt \
			> ${ACAPD_DOC}/draft-ietf-acap-book-03.txt
	${TR} '\r' '\n' < ${WRKSRC}/doc/draft-ietf-acap-email-03.txt \
			> ${ACAPD_DOC}/draft-ietf-acap-email-03.txt
	${TR} '\r' '\n' < ${WRKSRC}/doc/draft-ietf-acap-pers-03.txt \
			> ${ACAPD_DOC}/draft-ietf-acap-pers-03.txt
	${INSTALL_DATA} ${WRKSRC}/doc/rfc2244.txt ${ACAPD_DOC}
.endif

.if !defined(BATCH)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
